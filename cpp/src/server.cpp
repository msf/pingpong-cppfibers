#include <boost/fiber/all.hpp>
#include <chrono>
#include <grpcpp/grpcpp.h>
#include <mutex>
#include <thread>

#include "pingpong.grpc.pb.h"

using std::condition_variable;
using std::mutex;
using std::unique_lock;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using namespace pingpong;

// Custom fiber scheduler optimized for RPC
class RPCScheduler : public boost::fibers::algo::algorithm {

  boost::fibers::scheduler::ready_queue_type rqueue_{};
  mutable std::mutex mtx_{};
  std::condition_variable cv_{};
  bool flag_{false};

public:
  void awakened(boost::fibers::context *ctx) noexcept override {
    std::unique_lock<std::mutex> lk(mtx_);
    rqueue_.push_back(*ctx);
  }

  boost::fibers::context *pick_next() noexcept override {
    std::unique_lock<std::mutex> lk(mtx_);
    boost::fibers::context *ctx(nullptr);
    if (!rqueue_.empty()) {
      ctx = &rqueue_.front();
      rqueue_.pop_front();
    }
    return ctx;
  }

  bool has_ready_fibers() const noexcept override {
    std::unique_lock<std::mutex> lk(mtx_);
    return !rqueue_.empty();
  }

  void suspend_until(std::chrono::steady_clock::time_point const
                         &time_point) noexcept override {
    std::unique_lock<std::mutex> lk(mtx_);
    if (!flag_) {
      cv_.wait_until(lk, time_point);
    }
  }

  void notify() noexcept override {
    std::unique_lock<std::mutex> lk(mtx_);
    flag_ = true;
    cv_.notify_all();
  }
};

class BasicPingPongService final : public PingPong::Service {
  Status StreamPingPong(ServerContext *context,
                        ServerReaderWriter<Pong, Ping> *stream) override {
    boost::fibers::use_scheduling_algorithm<RPCScheduler>();

    // Simple fiber to handle each connection
    // boost::fibers::fiber([stream]()
    {
      Ping ping;
      while (stream->Read(&ping)) {
        // boost::this_fiber::sleep_for(std::chrono::microseconds(10));
        Pong pong;
        pong.set_sequence(ping.sequence());
        pong.set_timestamp(ping.timestamp());
        pong.set_server_timestamp(
            std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch())
                .count());
        pong.set_payload(ping.payload());

        if (!stream->Write(pong)) {
          break;
        }
      }
    }
    //).join();

    return Status::OK;
  }
};

int main() {
  BasicPingPongService service;
  ServerBuilder builder;

  // Basic setup without optimizations
  const auto addr = "unix:///tmp/pingpong.sock";
  builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
  // Performance tuning
  const auto max_size = 16 * 1024;
  builder.SetMaxMessageSize(max_size);
  builder.SetMaxReceiveMessageSize(max_size);
  builder.SetMaxSendMessageSize(max_size);

  // Resource quota for better control
  auto resource_quota = grpc::ResourceQuota("pingpong_quota");
  resource_quota.SetMaxThreads(2); // Main + worker thread
  builder.SetResourceQuota(resource_quota);

  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << addr << std::endl;
  server->Wait();

  return 0;
}

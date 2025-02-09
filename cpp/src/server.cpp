#include <boost/fiber/all.hpp>
#include <boost/program_options.hpp>
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

struct ServerConfig {
  bool use_fibers;
  bool sleep;
  int num_threads;
  std::string socket_path;
};

class PingPongService final : public PingPong::Service {
  const bool use_fibers_;
  const bool sleep_;

public:
  explicit PingPongService(bool use_fibers, bool sleep)
      : use_fibers_(use_fibers), sleep_(sleep) {}

  Status StreamPingPong(ServerContext *context,
                        ServerReaderWriter<Pong, Ping> *stream) override {
    if (use_fibers_) {
      boost::fibers::use_scheduling_algorithm<RPCScheduler>();
      return HandleStreamFiber(stream);
    }
    return HandleStreamThread(stream);
  }

private:
  Status HandleStreamFiber(ServerReaderWriter<Pong, Ping> *stream) {
    const bool use_sleep = sleep_;
    boost::fibers::fiber([use_sleep, stream]() {
      Ping ping;
      while (stream->Read(&ping)) {
        if (use_sleep) {
          boost::this_fiber::sleep_for(std::chrono::microseconds(4));
        }
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
    }).join();
    return Status::OK;
  }

  Status HandleStreamThread(ServerReaderWriter<Pong, Ping> *stream) {
    Ping ping;
    while (stream->Read(&ping)) {
      if (sleep_) {
        std::this_thread::sleep_for(std::chrono::microseconds(4));
      }
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
    return Status::OK;
  }
};

int main(int argc, char *argv[]) {
  namespace po = boost::program_options;
  po::options_description desc("Allowed options");
  desc.add_options()("fibers", po::value<bool>()->default_value(false),
                     "Use fibers")("sleep",
                                   po::value<bool>()->default_value(false),
                                   "Sleep 4microsecs before reply")(
      "threads", po::value<int>()->default_value(4),
      "Number of worker threads")(
      "socket", po::value<std::string>()->default_value("/tmp/pingpong.sock"),
      "Socket path");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  ServerConfig config{.use_fibers = vm["fibers"].as<bool>(),
                      .sleep = vm["sleep"].as<bool>(),
                      .num_threads = vm["threads"].as<int>(),
                      .socket_path = vm["socket"].as<std::string>()};

  PingPongService service(config.use_fibers, config.sleep);
  ServerBuilder builder;

  // Resource quota applies to both modes
  auto resource_quota = grpc::ResourceQuota("pingpong_quota");
  resource_quota.SetMaxThreads(config.num_threads);
  builder.SetResourceQuota(resource_quota);

  const auto max_size = 16 * 1024;
  builder.SetMaxMessageSize(max_size);
  builder.SetMaxReceiveMessageSize(max_size);
  builder.SetMaxSendMessageSize(max_size);

  builder.AddListeningPort("unix://" + config.socket_path,
                           grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  auto server = builder.BuildAndStart();
  std::cout << "Server running in " << (config.use_fibers ? "fiber" : "thread")
            << " mode with " << config.num_threads << " threads"
            << " with sleep? " << config.sleep << "\n";
  server->Wait();

  return 0;
}

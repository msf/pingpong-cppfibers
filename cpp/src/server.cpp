#include "pingpong.grpc.pb.h"
#include <boost/fiber/all.hpp>
#include <chrono>
#include <grpcpp/grpcpp.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using namespace pingpong;

class BasicPingPongService final : public PingPong::Service {
  Status StreamPingPong(ServerContext *context,
                        ServerReaderWriter<Pong, Ping> *stream) override {
    // Simple fiber to handle each connection
    boost::fibers::fiber([stream]() {
      Ping ping;
      while (stream->Read(&ping)) {
        Pong pong;
        pong.set_sequence(ping.sequence());
        pong.set_timestamp(ping.timestamp());
        pong.set_server_timestamp(
            std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch())
                .count());

        if (!stream->Write(pong)) {
          break;
        }
      }
    }).join();

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
  resource_quota.SetMaxThreads(2);  // Main + worker thread
  builder.SetResourceQuota(resource_quota);

  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << addr << std::endl;
  server->Wait();

  return 0;
}

#include <boost/fiber/all.hpp>
#include <grpcpp/grpcpp.h>
#include "pingpong.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using namespace pingpong;

class BasicPingPongService final : public PingPong::Service {
    Status StreamPingPong(ServerContext* context,
                         ServerReaderWriter<Pong, Ping>* stream) override {
        // Simple fiber to handle each connection
        boost::fibers::fiber([stream]() {
            Ping ping;
            while (stream->Read(&ping)) {
                Pong pong;
                pong.set_sequence(ping.sequence());
                pong.set_timestamp(ping.timestamp());
                pong.set_server_timestamp(
                    std::chrono::system_clock::now().time_since_epoch().count()
                );
                
                stream->Write(pong);
            }
        }).join();
        
        return Status::OK;
    }
};

int main() {
    BasicPingPongService service;
    ServerBuilder builder;
    
    // Basic setup without optimizations
    builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on port 50051" << std::endl;
    server->Wait();
    
    return 0;
}

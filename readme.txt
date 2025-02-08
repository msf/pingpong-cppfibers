# High-Performance PingPong Benchmark

A high-performance gRPC ping-pong benchmark using C++ Boost Fibers for the server and Go for the client.

## Prerequisites

- Clang 19
- CMake 3.15+
- Go 1.21+
- Protocol Buffers compiler
- gRPC development files
- Boost development files

On Debian/Ubuntu:
```bash
# Install build tools
apt install build-essential cmake clang-19 protobuf-compiler

# Install gRPC development files
apt install libgrpc++-dev libgrpc-dev protobuf-compiler-grpc

# Install Boost
apt install libboost-all-dev

# Install Go if not already installed
apt install golang-go

# Install Go protobuf plugins
go install google.golang.org/protobuf/cmd/protoc-gen-go@latest
go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@latest
```

## Building

Simply run:
```bash
make all
```

This will:
1. Generate protocol buffer code
2. Build the C++ server
3. Build the Go client

## Running

1. Start the server:
```bash
./cpp/build/server
```

2. In another terminal, run the client:
```bash
./bin/client
```

## Performance Tuning

The system is configured for maximum performance:
- Uses Unix Domain Sockets for IPC
- CPU pinning (server on core 0, client on core 1)
- Custom fiber scheduler for optimal RPC handling
- Tuned gRPC parameters
- Optimized build flags
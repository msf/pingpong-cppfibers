.PHONY: all clean proto cpp go

all: proto cpp go

# Protocol Buffers
proto:
	mkdir -p cpp/build/proto
	mkdir -p go/pkg/proto
	protoc -I=proto --cpp_out=cpp/build/proto --grpc_out=cpp/build/proto \
		--plugin=protoc-gen-grpc=`which grpc_cpp_plugin` proto/pingpong.proto
	protoc -I=proto --go_out=go/pkg/proto --go-grpc_out=go/pkg/proto \
		proto/pingpong.proto

# C++ Server
cpp: proto
	cd cpp && cmake -B build -DCMAKE_CXX_COMPILER=clang++-19
	cd cpp && cmake --build build -j

# Go Client
go: proto
	cd go && go mod tidy && go build -o ../bin/client ./cmd/client

clean:
	rm -rf cpp/build
	rm -rf bin/
	rm -rf go/pkg/proto
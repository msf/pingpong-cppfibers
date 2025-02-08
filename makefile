.PHONY: all clean proto cpp go

all: proto cpp go

# Protocol Buffers
proto:
	mkdir -p cpp/build/proto
	mkdir -p go/pkg/proto
	protoc -I=proto --cpp_out=cpp/build/proto --grpc_out=cpp/build/proto \
		--plugin=protoc-gen-grpc=`which grpc_cpp_plugin` proto/pingpong.proto
	protoc -I=proto --go_out=go --go-grpc_out=go \
		proto/pingpong.proto

# C++ Server
cpp: proto
	cd cpp && cmake -B build 
	cd cpp && cmake --build build -j
	cd cpp && cp -f build/server ../bin/server

# Go Client
go: proto
	cd go && go mod tidy && go build -o ../bin/client ./cmd/client

clean:
	rm -rf cpp/build
	rm -rf bin/
	rm -rf go/pkg/proto

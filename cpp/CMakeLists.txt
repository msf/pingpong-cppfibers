cmake_minimum_required(VERSION 3.15)
project(pingpong_server CXX)

set(CMAKE_CXX_COMPILER clang++-19)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# Find required packages
find_package(Boost REQUIRED COMPONENTS fiber program_options)
find_package(gRPC CONFIG REQUIRED)
find_package(Protobuf REQUIRED)

# Add protobuf-generated files
add_library(proto
    build/proto/pingpong.grpc.pb.cc
    build/proto/pingpong.grpc.pb.h
    build/proto/pingpong.pb.cc
    build/proto/pingpong.pb.h
)

# Ensure PIC for the library
set_property(TARGET proto PROPERTY POSITION_INDEPENDENT_CODE ON)


target_link_libraries(proto
    PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++
)
target_include_directories(proto
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
    build/proto
)

# Server executable
add_executable(server src/server.cpp)

# Force consistent compiler for the executable
set_property(TARGET server PROPERTY CXX_STANDARD 20)
set_property(TARGET server PROPERTY CXX_STANDARD_REQUIRED ON)


target_link_libraries(server
    PRIVATE
    proto
    Boost::fiber
    Boost::program_options
    gRPC::grpc++
)

# Compiler flags
target_compile_options(server
    PRIVATE
    -O3
    -march=native
    -mtune=native
    -flto
    -Wall
    -Wextra
    -fPIC
)


# Enable IPO/LTO if available
include(CheckIPOSupported)
check_ipo_supported(RESULT supported OUTPUT error)
if(supported)
    set_property(TARGET server PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()


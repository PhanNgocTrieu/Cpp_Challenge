# find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

cmake_minimum_required(VERSION 3.0.0)
project(libsocket VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")  
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

set(SOCK_HDR include/libSocket.h)

set(SOCK_SRC src/libSocket.cpp)

# After setting we need to generate the library by this below command
add_library(libsocket STATIC ${SOCK_HDR} ${SOCK_SRC})

target_compile_options(libsocket PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)



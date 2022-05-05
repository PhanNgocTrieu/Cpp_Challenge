# find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

include_directories(include)

set(SOCK_HDR include/libSocket.h)

set(SOCK_SRC src/libSocket.cpp)

# After setting we need to generate the library by this below command
add_library(libsocket STATIC ${SOCK_HDR} ${SOCK_SRC})


target_compile_options(libsocket PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)



find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

# include_directories(include)

# set(SOCK_HDR include/sock.h)

# set(SOCK_SRC src/sock.cpp)

# After setting we need to generate the library by this below command
# add_library(socket STATIC ${SOCK_HDR} ${SOCK_SRC})

# add_executable(socket src/synchronousTimer.cpp)

# target_compile_options(socket PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)



# find_package(Boost 1.69 REQUIRED COMPONENTS log timer)
cmake_minimum_required(VERSION 3.0.0)
project(IO_LIBRARIES_BUILDING VERSION 0.1.0)

include_directories(include)

set(IOLIB_HRD include/IOLibrary.h)

set(IOLIB_SRC src/IOLibrary.cpp)

# After setting we need to generate the library by this below command
add_library(iolib STATIC ${IOLIB_HRD} ${IOLIB_SRC})

target_compile_options(iolib PRIVATE -std=c++11 -Wall)
# target_link_libraries(Boost::log Boost::thread ${CMAKE_THREAD_LIBS_INIT})
add_subdirectory(examples)



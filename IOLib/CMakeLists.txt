find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

include_directories(include)

set(IOLIB_HRD include/IOLibrary.h)

set(IOLIB_SRC src/IOLibrary.cpp)

# After setting we need to generate the library by this below command
add_library(iolib STATIC ${IOLIB_HRD} ${IOLIB_SRC})

target_compile_options(iolib PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)



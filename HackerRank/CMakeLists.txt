find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

include_directories(include)

set(HACK_HDR include/arrayProblems.h)

set(HACK_SRC src/arrayProblems.cpp)

# After setting we need to generate the library by this below command
add_library(hackerRank STATIC ${HACK_HDR} ${HACK_SRC})

target_compile_options(hackerRank PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)



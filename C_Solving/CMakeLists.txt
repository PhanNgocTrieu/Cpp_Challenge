find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

include_directories(include)

set(CSOLVING_HDR include/solvingC.h)

set(CSOLVING_SRC src/solvingC.cpp)

# After setting we need to generate the library by this below command
add_library(cSolving STATIC ${CSOLVING_HDR} ${CSOLVING_SRC})

target_compile_options(cSolving PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)

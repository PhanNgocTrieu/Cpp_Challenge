

include_directories(include)

set(CODEFORCE_HDR  include/codeForce.h
)

set(CODEFORCE_SRC  src/codeForce.cpp
)

# After setting we need to generate the library by this below command
add_library(codeForce STATIC ${CODEFORCE_HDR} ${CODEFORCE_SRC})

target_compile_options(codeForce PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)
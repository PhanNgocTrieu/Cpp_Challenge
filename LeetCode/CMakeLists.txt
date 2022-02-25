find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

include_directories(include)

set(LEETCD_HDR  include/leetCode.h
                include/data.h
)

set(LEETCD_SRC  src/leetCode.cpp
                
)

# After setting we need to generate the library by this below command
add_library(leetcode STATIC ${LEETCD_HDR} ${LEETCD_SRC})

target_compile_options(leetcode PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)



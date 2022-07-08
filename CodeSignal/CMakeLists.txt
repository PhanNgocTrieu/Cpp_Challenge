cmake_minimum_required(VERSION 3.0.0)
project(CODESIGNAL VERSION 0.1.0)

include_directories(include)

set(CODESIGNAL_HDR  include/Intro.h
                    include/Core.h
                    include/supportedFunction.h
)

set(CODESIGNAL_SRC  src/Core.cpp

)

# After setting we need to generate the library by this below command
add_library(codeSignal STATIC ${CODESIGNAL_HDR} ${CODESIGNAL_SRC})

target_compile_options(codeSignal PRIVATE -std=c++11 -Wall)

# add_subdirectory(Intro)
# add_subdirectory(TheCore)
add_subdirectory(examples)
cmake_minimum_required(VERSION 3.0.0)
project(CODE_LEARN VERSION 0.1.0)

add_executable(codeLearn ./questionQuery.cpp)

target_compile_options(codeLearn PRIVATE -std=c++11 -Wall)



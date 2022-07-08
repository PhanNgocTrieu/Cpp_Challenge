cmake_minimum_required(VERSION 3.0.0)
project(CompetiveChallenge VERSION 0.1.0)

include_directories(include)
set(COMPETIVIE_SRC src/easyCompetitive.cpp)

target_compile_options(competitive PRIVATE -std=c++11 -Wall)



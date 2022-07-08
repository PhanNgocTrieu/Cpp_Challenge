cmake_minimum_required(VERSION 3.0.0)
project(Shell VERSION 0.1.0)

include_directories(include)

set(MES_INC include/shell.h
            include/define.h
)

set(MES_SRC src/shell.cpp)

add_library(Shell STATIC ${MES_INC} ${MES_SRC})

# add_subdirectory(examples)

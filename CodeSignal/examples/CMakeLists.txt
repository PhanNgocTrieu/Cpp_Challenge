add_executable(codeSignalProblems main.cpp)

target_compile_options(codeSignalProblems PRIVATE -std=c++11 -Wall)

target_link_libraries(codeSignalProblems DTST ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(codeSignalProblems PRIVATE ../include)

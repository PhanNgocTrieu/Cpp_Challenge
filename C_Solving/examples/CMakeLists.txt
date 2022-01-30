add_executable(solvingc main.cpp)

target_compile_options(solvingc PRIVATE -std=c++11 -Wall)

target_link_libraries(solvingc cSolving ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(solvingc PRIVATE ../include)



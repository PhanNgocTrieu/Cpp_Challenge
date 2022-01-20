add_executable(solving main.cpp)

target_compile_options(solving PRIVATE -std=c++11 -Wall)

target_link_libraries(solving cSolving ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(solving PRIVATE ../include)



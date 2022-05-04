add_executable(test test.cpp)

target_compile_options(test PRIVATE -std=c++11 -Wall)

target_link_libraries(test COMPLEX ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(test PRIVATE ../include)

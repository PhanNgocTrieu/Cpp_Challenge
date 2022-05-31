add_executable(_management main.cpp)

target_compile_options(_management PRIVATE -std=c++11 -Wall)

target_link_libraries(_management libManagement ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(_management PRIVATE ../include)
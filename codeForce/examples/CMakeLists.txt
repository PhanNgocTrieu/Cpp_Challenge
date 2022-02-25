add_executable(codeforcing main.cpp)

target_compile_options(codeforcing PRIVATE -std=c++11 -Wall)

target_link_libraries(codeforcing codeForce ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(codeforcing PRIVATE ../include)

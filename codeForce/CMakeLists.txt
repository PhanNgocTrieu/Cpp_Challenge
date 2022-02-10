
find_package(Boost 1.78 REQUIRED COMPONENTS thread log program_options)

add_executable(codeForce minMaxSwap.cpp)

target_compile_options(codeForce PRIVATE -std=c++11 -Wall)

target_link_libraries(codeForce ${CMAKE_THREAD_LIBS_INIT})


## Using for boost::thread
target_link_libraries(codeForce Boost::log Boost::program_options Boost::thread ${CMAKE_THREAD_LIBS_INIT})
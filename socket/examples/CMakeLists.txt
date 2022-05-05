
find_package(Boost 1.69 REQUIRED COMPONENTS thread log program_options)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)

add_executable(async ansynchronousTimer.cpp)
add_executable(sync synchronousTimer.cpp)
add_executable(binding handleBinding.cpp)
add_executable(hdlFunc handleFunction.cpp)

target_compile_options(async PRIVATE -std=c++11 -Wall)
target_compile_options(sync PRIVATE -std=c++11 -Wall)
target_compile_options(binding PRIVATE -std=c++11 -Wall)
target_compile_options(hdlFunc PRIVATE -std=c++11 -Wall)

add_executable(multiThread multithreadTimer.cpp)
target_compile_options(multiThread PRIVATE -std=c++11 -Wall)
target_link_libraries(multiThread ${CMAKE_THREAD_LIBS_INIT})


## Using for boost::thread
target_link_libraries(multiThread Boost::log Boost::program_options Boost::thread ${CMAKE_THREAD_LIBS_INIT})
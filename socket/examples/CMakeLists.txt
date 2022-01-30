
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

add_executable(async ansynchronousTimer.cpp)
add_executable(sync synchronousTimer.cpp)
add_executable(binding handleBinding.cpp)
add_executable(hdlFunc handleFunction.cpp)

target_compile_options(async PRIVATE -std=c++11 -Wall)
target_compile_options(sync PRIVATE -std=c++11 -Wall)
target_compile_options(binding PRIVATE -std=c++11 -Wall)
target_compile_options(hdlFunc PRIVATE -std=c++11 -Wall)


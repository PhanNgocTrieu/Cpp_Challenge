find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

add_executable(calSine Sine.cpp)
target_compile_options(calSine PRIVATE -std=c++11 -Wall)

add_executable(giaithua giaiThua.cpp)
target_compile_options(giaithua PRIVATE -std=c++11 -Wall)



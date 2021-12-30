add_executable(dataStructureProlems main.cpp)

target_compile_options(dataStructureProlems PRIVATE -std=c++11 -Wall)

target_link_libraries(dataStructureProlems DTST ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(dataStructureProlems PRIVATE ../include)

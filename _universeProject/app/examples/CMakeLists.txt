add_executable(_triangle triangleDrawing.cpp)
add_executable(_demo main.cpp)
add_executable(_sunMonEarth sunMonEarth.cpp)

target_compile_options(_triangle PRIVATE -std=c++11 -Wall)
target_compile_options(_demo PRIVATE -std=c++11 -Wall)
target_compile_options(_sunMonEarth PRIVATE -std=c++11 -Wall)

target_link_libraries(_triangle libs ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(_demo libs ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(_sunMonEarth libs ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(_triangle PRIVATE ../include)
target_include_directories(_demo PRIVATE ../include)
target_include_directories(_sunMonEarth PRIVATE ../include)
add_executable(graphicProblems main.cpp)

target_compile_options(graphicProblems PRIVATE -std=c++11 -Wall)

target_link_libraries(graphicProblems graphic ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(graphicProblems PRIVATE ../include)

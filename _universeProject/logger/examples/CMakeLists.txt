add_executable(logExample loggerTest.cpp)

target_compile_options(logExample PRIVATE -std=c++11 -Wall)

target_link_libraries(logExample liblogger ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(logExample PRIVATE ../include)
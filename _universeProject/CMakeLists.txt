cmake_minimum_required(VERSION 3.10)
project(UniProject VERSION 0.1.0)


set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_subdirectory(logger)
add_subdirectory(game)
cmake_minimum_required(VERSION 3.0.0)
project(CPPChallenge VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")  

# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_link_options($<$<CONFIG:RELEASE>:-s>)
add_definitions(-DBOOST_LOG_DYN_LINK)


add_executable(_littleChallenge Advoid_Ghost_Room.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
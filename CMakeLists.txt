cmake_minimum_required(VERSION 3.0.0)
project(CPPChallenge VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")  
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_link_options($<$<CONFIG:RELEASE>:-s>)
# add_executable(CPPChallenge Graphic/handlingFile/writingFile.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

add_subdirectory(C_Solving)
add_subdirectory(Graph)
add_subdirectory(CodeSignal)
add_subdirectory(competitiveProblems)
add_subdirectory(HackerRank)
add_subdirectory(LeetCode)
add_subdirectory(DataStructure)

# add_definitions(-DBOOST_LOG_DYN_LINK)



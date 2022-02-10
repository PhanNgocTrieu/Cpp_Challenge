cmake_minimum_required(VERSION 3.0.0)
project(CPPChallenge VERSION 0.1.0)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")  
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Boost COMPONENTS log program_options thread REQUIRED)


add_link_options($<$<CONFIG:RELEASE>:-s>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

add_subdirectory(IOLib)
add_subdirectory(C_Solving)
add_subdirectory(codeForce)
# add_subdirectory(Graph)
add_subdirectory(CodeSignal)
add_subdirectory(competitiveProblems)
add_subdirectory(HackerRank)
add_subdirectory(LeetCode)
add_subdirectory(DataStructure)
add_subdirectory(socket)
# add_definitions(-DBOOST_LOG_DYN_LINK)


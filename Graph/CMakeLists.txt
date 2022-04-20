# find_package(Boost 1.69 REQUIRED COMPONENTS log timer)

# find_package(PkgConfig REQUIRED)

# pkg_check_modules(libsocketcan REQUIRED libsocketcan>=0.0.10)

include_directories(include)

set(GRAPH_SRC src/Graph.cpp)

set(GRAPH_HDR include/Graph.h)

add_library(graphic STATIC ${GRAPH_SRC} ${GRAPH_HDR})

target_compile_options(graphic PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)

#add_subdirectory(ut)


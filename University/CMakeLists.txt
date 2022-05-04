include_directories(include)

set(INC include/complex.h)
set(SRC src/complex.cpp)

add_library(COMPLEX STATIC ${INC} ${SRC})

add_subdirectory(examples)

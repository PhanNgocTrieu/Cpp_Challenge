include_directories(include)

set(DTST_HDR    include/dataStructure.h
                include/linkedlist.h
                include/BST.h
)

set(DTST_SRC    src/dataStructure.cpp

)

# After setting we need to generate the library by this below command
add_library(DTST STATIC ${DTST_HDR} ${DTST_SRC})

target_compile_options(DTST PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)



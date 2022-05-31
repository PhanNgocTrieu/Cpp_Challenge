include_directories(include)

set(MAN_HDR include/Display.h
            include/common.h
            include/Employee.h
            include/Developer.h
            include/Manager.h
            include/Controller.h
)

set(MAN_SRC src/Display.cpp
            src/Employee.cpp
            src/Developer.cpp
            src/Manager.cpp
            src/Controller.cpp
)

add_library(libManagement STATIC ${MAN_HDR} ${MAN_SRC})

target_compile_options(libManagement PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)

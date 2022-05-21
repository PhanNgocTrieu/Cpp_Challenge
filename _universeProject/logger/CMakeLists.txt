include_directories(include)

set(LOG_HDR include/logger.h
            include/log_common.h
)

set(LOG_SRC src/logger.cpp)

add_library(liblogger STATIC ${LOG_HDR} ${LOG_SRC})

target_compile_options(liblogger PRIVATE -std=c++11 -Wall)

add_subdirectory(examples)

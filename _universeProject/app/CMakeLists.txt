find_package(Boost ${BOOST_VERSION} REQUIRED COMPONENTS log program_options)
find_package(PkgConfig REQUIRED)
find_package(glfw3 REQUIRED)

set(OpenGL_GL_PREFERENCE LEGACY)

find_package(OpenGL REQUIRED)

pkg_check_modules(OPENGL REQUIRED glesv2)
# pkg_check_modules(LIBPANGOFT2 REQUIRED pangoft2)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)

set (APP_SRC    src/_reference.cpp
                # src/_button.cpp
)

# add_executable(app ${APP_SRC})

add_library(libs STATIC ${APP_SRC})

target_compile_options(libs PRIVATE -std=c++11 -Wall ${OPENGL_CFLAGS} ${GLFW_CFLAGS}) # ${LIBPANGOFT2_CFLAGS}
target_include_directories(libs PRIVATE ${OPENGL_INCLUDE_DIRS}  ${GLFW_INCLUDE_DIRS} 
        include
    ../logger/include
)

target_link_libraries(libs  liblogger 
                            Boost::log 
                            Boost::program_options 
                            glfw 
                            OpenGL::GL 
                            ${CMAKE_THREAD_LIBS_INIT} 
                            ${OPENGL_LIBRARIES} 
                            ${GLFW_LIBRARIES})

link_libraries(libs  ${OPENGL_gl_LIBRARY} glfw)

#target_include_directories(app PRIVATE ../include)

add_subdirectory(examples)
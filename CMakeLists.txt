cmake_minimum_required(VERSION 3.25)

project(opengl3d)

find_package(glfw3 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
add_executable(opengl3d main.cpp glad.c)
target_link_libraries(opengl3d
    glfw
    "-framework OpenGL")
target_include_directories(opengl3d PUBLIC glad/include)

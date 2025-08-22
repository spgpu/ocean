cmake_minimum_required(VERSION 3.14)
project(ocean)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLAD
add_library(glad lib/glad/src/gl.c)
target_include_directories(glad PUBLIC lib/glad/include)

# GLFW
add_subdirectory(lib/glfw-3.4)

# Create executable
add_executable(ocean src/main.cpp)
target_link_libraries(ocean PRIVATE glfw glad)

# Extra system libs on Linux
if(UNIX AND NOT APPLE)
  find_package(OpenGL REQUIRED)
  target_link_libraries(ocean PRIVATE OpenGL::GL X11 Xrandr Xinerama Xi Xcursor dl pthread)
endif()

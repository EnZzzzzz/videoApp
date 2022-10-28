cmake_minimum_required(VERSION 3.3.2)
project(videoApp)
set(CMAKE_CXX_STANDARD 14)

option(USE_GLFW "use glfw to render window" ON)

set(INCLUDE_DIRS "")   # include 目录
set(LINK_DIRS "")      # link 目录
set(LINK_LIBS "")      # link 库名称
set(FILES "")          # 项目中的文件

list(APPEND INCLUDE_DIRS src)
list(APPEND INCLUDE_DIRS src/vendors)
list(APPEND INCLUDE_DIRS Denpendiencies)
list(APPEND LINK_DIRS    Denpendiencies/GLFW)

file(GLOB_RECURSE effectTask   src/effectTasks/*.cpp)
file(GLOB_RECURSE export       src/export/*.cpp)
file(GLOB_RECURSE stb_image    src/vendors/stb_image/*.cpp)
file(GLOB_RECURSE glm          src/vendors/glm/*.cpp)
file(GLOB_RECURSE glad         src/vendors/glad/*.c)
list(APPEND FILES ${effectTask})
list(APPEND FILES ${export})
list(APPEND FILES ${stb_image})
list(APPEND FILES ${glm})
list(APPEND FILES ${glad})

set(forAdd src/effectTasks/TaskTriangle.cpp src/effectTasks/TaskTriangle.h src/vendors/stb_image/stb_image_write.cpp)

include_directories(${INCLUDE_DIRS})
link_directories(${LINK_DIRS})
add_executable(videoApp src/main.cpp ${FILES} ${forAdd})

# glfw
target_link_libraries(videoApp glfw3 pthread)
target_link_libraries(videoApp glfw3 pthread Xrandr Xi X11 Xcursor)

# Osmesa
target_link_libraries(videoApp dl m OSMesa)

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
file(GLOB_RECURSE glElement    src/glElement/*.cpp)
file(GLOB_RECURSE stb_image    src/vendors/stb_image/*.cpp)
file(GLOB_RECURSE glm          src/vendors/glm/*.cpp)
file(GLOB_RECURSE glad         src/vendors/glad/*.c)
file(GLOB_RECURSE imgui        src/vendors/imgui/*.*)
list(APPEND FILES ${effectTask})
list(APPEND FILES ${export})
list(APPEND FILES ${glElement})
list(APPEND FILES ${stb_image})
list(APPEND FILES ${glm})
list(APPEND FILES ${glad})
list(APPEND FILES ${imgui})

if (USE_GLFW)
message(STATUS "Using glfw")
list(APPEND LINK_LIBS glfw3)
list(APPEND LINK_LIBS pthread)
list(APPEND LINK_LIBS Xrandr)
list(APPEND LINK_LIBS Xi)
list(APPEND LINK_LIBS X11)
list(APPEND LINK_LIBS Xcursor)
endif ()

# OSMesa libs
list(APPEND LINK_LIBS OSMesa)
list(APPEND LINK_LIBS dl)
list(APPEND LINK_LIBS m)


set(forAdd src/effectTasks/TaskTriangle.cpp src/effectTasks/TaskTriangle.h src/vendors/stb_image/stb_image_write.cpp ${glElement} src/export/Context.h src/export/Context.h src/export/Context.h src/effectTasks/LOG28Framebuffer1.cpp src/effectTasks/LOG28Framebuffer1.h)

include_directories(${INCLUDE_DIRS})
link_directories(${LINK_DIRS})
add_executable(videoApp src/main.cpp ${FILES} ${forAdd})
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})

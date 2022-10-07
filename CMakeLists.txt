cmake_minimum_required(VERSION 3.3.2)
project(videoApp)
set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/vendors)
include_directories(Denpendiencies)
link_directories(Denpendiencies/GLFW)

set(forAdd src/effectTasks/TaskTriangle.cpp src/effectTasks/TaskTriangle.h src/vendors/stb_image/stb_image_write.cpp)


file(GLOB_RECURSE effectTask   src/effectTasks/*.cpp)
file(GLOB_RECURSE export       src/export/*.cpp)
#file(GLOB_RECURSE exclude      src/exclude/*.cpp)
file(GLOB_RECURSE stb_image    src/vendors/stb_image/*.cpp)
file(GLOB_RECURSE glm          src/vendors/glm/*.cpp)
file(GLOB_RECURSE glad         src/vendors/glad/*.c)


add_executable(videoApp src/main.cpp ${effectTask} ${export} ${stb_image} ${glm}
                        ${glad}
#        ${exclude}
        ${forAdd})

# glfw
#target_link_libraries(videoApp glfw3 pthread)
#target_link_libraries(videoApp glfw3 pthread Xrandr Xi X11 Xcursor)

# Osmesa
target_link_libraries(videoApp dl m OSMesa)

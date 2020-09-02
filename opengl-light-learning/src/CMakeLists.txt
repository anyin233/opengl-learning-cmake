set(CMAKE_TOOLCHAIN_FILE "F:/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.0.0)

add_executable(opengl-light-learn main.cpp)

#添加来自vcpkg的库
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(opengl-light-learn PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(opengl-light-learn PRIVATE glad::glad)

find_package(glm CONFIG REQUIRED)
target_link_libraries(opengl-light-learn PRIVATE glm)

target_link_libraries(opengl-light-learn PRIVATE CameraFunc)
target_link_libraries(opengl-light-learn PRIVATE ShaderFunc)
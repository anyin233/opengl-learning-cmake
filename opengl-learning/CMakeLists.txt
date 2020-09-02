set(CMAKE_TOOLCHAIN_FILE "F:/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.0.0)
project(opengl-learning VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(shader)
add_subdirectory(camera)

include_directories(lib)

add_executable(opengl-learning main.cpp)

find_package(glad CONFIG REQUIRED)
target_link_libraries(opengl-learning PUBLIC glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(opengl-learning PUBLIC glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(opengl-learning PRIVATE glm)

target_link_libraries(opengl-learning PUBLIC ShaderFunc)
target_link_libraries(opengl-learning PUBLIC CameraFunc)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
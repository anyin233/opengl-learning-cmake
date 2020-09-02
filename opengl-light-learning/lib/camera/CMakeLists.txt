cmake_minimum_required(VERSION 3.3.0)
project(camera)

include_directories(.)
aux_source_directory(. SHADER_DIR)
add_library(CameraFunc ${SHADER_DIR})

find_package(glad CONFIG REQUIRED)
target_link_libraries(CameraFunc PUBLIC glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(CameraFunc PUBLIC glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(CameraFunc PUBLIC glm)
set(CMAKE_TOOLCHAIN_FILE "F:/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.3.0)
project(camera)

aux_source_directory(. SHADER_DIR)
add_library(ShaderFunc ${SHADER_DIR})

find_package(glad CONFIG REQUIRED)
target_link_libraries(ShaderFunc PUBLIC glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(ShaderFunc PUBLIC glfw)
cmake_minimum_required(VERSION 3.23)
project(CoffeeProject VERSION 1.0.0)

set(ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(../third-party/glfw third_party/glfw)

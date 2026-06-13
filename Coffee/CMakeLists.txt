cmake_minimum_required(VERSION 3.23)
project(CoffeeProject VERSION 1.0.0)

set(ENGINE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
message("Engine incl dir: ";${ENGINE_INCLUDE_DIR})

add_subdirectory(src)

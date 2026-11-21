add_library(Memory STATIC)

target_sources(
  Memory
  PUBLIC FILE_SET HEADERS BASE_DIRS ${ENGINE_INCLUDE_DIR}
         #
         FILES 
         ${ENGINE_INCLUDE_DIR}/Coffee/Memory/Memory.h
         ${ENGINE_INCLUDE_DIR}/Coffee/Memory/Buffer.h
         ${ENGINE_INCLUDE_DIR}/Coffee/Memory/Texture.h
  PRIVATE Memory.cpp)

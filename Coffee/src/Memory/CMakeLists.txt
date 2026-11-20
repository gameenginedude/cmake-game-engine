add_library(Memory STATIC)

target_sources(
  Memory
  PUBLIC FILE_SET HEADERS BASE_DIRS ${ENGINE_INCLUDE_DIR}
         #
         FILES ${ENGINE_INCLUDE_DIR}/Coffee/Loaders/Memory.h
  PRIVATE Memory.cpp)

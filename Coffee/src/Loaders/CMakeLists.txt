add_library(Loaders INTERFACE)

target_sources(
  Loaders
  PUBLIC FILE_SET HEADERS BASE_DIRS ${ENGINE_INCLUDE_DIR}
         #
         FILES ${ENGINE_INCLUDE_DIR}/Coffee/Loaders/GltfLoader.h
  PRIVATE)

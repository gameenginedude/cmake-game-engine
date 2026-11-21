add_library(Graphics STATIC)

target_sources(
  Graphics
  PUBLIC FILE_SET
         HEADERS
         BASE_DIRS
         ${ENGINE_INCLUDE_DIR}
         ${ENGINE_ASSETS_DIR}
         #
         FILES
         ${ENGINE_INCLUDE_DIR}/Coffee/Graphics/Graphics.h
         ${ENGINE_INCLUDE_DIR}/Coffee/Graphics/Scene.h
  PRIVATE Graphics.cpp)

target_link_libraries(Graphics PRIVATE Renderer)

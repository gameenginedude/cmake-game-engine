include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)

add_subdirectory(Core)
add_subdirectory(Graphics)
add_subdirectory(Renderer)
add_subdirectory(Loaders)
add_subdirectory(Memory)

add_library(Coffee INTERFACE)

target_sources(
  Coffee
  PUBLIC FILE_SET HEADERS BASE_DIRS ${ENGINE_INCLUDE_DIR}
         #
         FILES ${ENGINE_INCLUDE_DIR}/Coffee/Coffee.h)

target_link_libraries(Coffee INTERFACE Core Graphics)

coffee_target_debug_compile_defs(Core PUBLIC)
coffee_target_debug_compile_defs(Graphics PUBLIC)
coffee_target_debug_compile_defs(Renderer PUBLIC)
coffee_target_debug_compile_defs(Loaders INTERFACE)
coffee_target_debug_compile_defs(Memory PUBLIC)

# --- INSTALL LIBS ---

install(
  TARGETS Coffee Core Graphics Renderer Loaders
  EXPORT CoffeeTargets
  FILE_SET HEADERS)

include(GNUInstallDirs)
install(
  EXPORT CoffeeTargets
  NAMESPACE Coffee::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Coffee)
install(
    DIRECTORY ${ENGINE_ASSETS_DIR}
    DESTINATION ${CMAKE_INSTALL_DATADIR}/Coffee)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/CoffeeConfigVersion.cmake
  COMPATIBILITY ExactVersion)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/CoffeeConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/CoffeeConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Coffee)

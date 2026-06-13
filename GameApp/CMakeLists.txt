cmake_minimum_required(VERSION 3.23)
project(GameApp VERSION 1.0.0)

add_executable(game)
target_sources(game PRIVATE game.cpp)

# OPTION 1: Link to the binary directly
# --- BAD ---
target_include_directories(game PRIVATE ../install/include)
find_library(
  engineLibFileLocation
  NAMES Core
  PATHS ../install/lib)
target_link_libraries(game PRIVATE ${engineLibFileLocation})
# --- BAD ---

# OPTION 2: Build the ext lib from source
# add_subdirectory(./third-party/EngineLib) target_link_libraries(game PRIVATE
# engine)

install(TARGETS game)

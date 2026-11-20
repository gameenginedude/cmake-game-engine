

#pragma once

#include "Coffee/Graphics/Scene.h"
#include "Coffee/Logs.h"
#include <string_view>

namespace Coffee {
namespace Loaders {

class CppFriendlyFormat {};

class GltfLoader {
public:
  GltfLoader() = default;

  static void LoadFrom3DFile(const std::string_view &filepath,
                             CppFriendlyFormat &fileData) {
    COFFEE_PRINT("Loaded file " << filepath << " successfully");
  }

  static void ExtractSceneInfoFrom3DFile(CppFriendlyFormat &fileData,
                                         Gfx::Scene &scene) {
    COFFEE_PRINT("Extracting meshes...");
    COFFEE_PRINT("Extracting transformations...");
    COFFEE_PRINT("Extracting materials...");
    COFFEE_PRINT("Extracting lights...");
    COFFEE_PRINT("Extracting cameras...");
    COFFEE_PRINT("Extracting other shi...");
  }
};
} // namespace Loaders
} // namespace Coffee

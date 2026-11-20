#pragma once

#include "Coffee/Logs.h"
#include <string_view>
namespace Coffee {
namespace Loaders {

inline void LoadShadersAndCompile(const std::string_view &shaderCode,
                                  std::byte *shaderByteCode) {
  COFFEE_PRINT(
      "parsed shader code into byte code, ready to be used in pipelines")
}
} // namespace Loaders
} // namespace Coffee

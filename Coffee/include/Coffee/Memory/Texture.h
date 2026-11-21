

#pragma once

#include <cstdint>

namespace Coffee {
namespace Memory {
enum class GpuTextureType : uint8_t {
  None = 0,
  Texture2D,
  Texture3D,
  Cubemap,
  // ... so on
};
enum class GpuTextureFormat : uint8_t { None = 0, R, RG, RGB, RGBA, Depth };

struct TextureConfig {
  uint16_t width;
  uint16_t height;
  GpuTextureType textureType;
  GpuTextureFormat textureFormat;
};

// texture views, similar to buffer views
class TextureView {};

// a general texture class that defines a simple image (can have enum types for
// different properties of a texture like above). can also template this for
// custom textures. in my engine, i have templated texture class
class Texture {};
}
}

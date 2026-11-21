#pragma once

#include "Coffee/Logs.h"
#include "Coffee/Memory/Buffer.h"
#include "Coffee/Memory/Texture.h"

namespace Coffee {
namespace Memory {

// just a container that has all the views into the buffers and textures
struct GpuSavedData {
  BufferView vertexView{};
  BufferView indexView{};
  BufferView transformView{};
  BufferView lightsView{};
  BufferView customDataView{};
  // .. so on

  TextureView colorView{};
  TextureView normalView{};
  TextureView roughnessMetallicView{};
  // .. son on
};

// has the raw memory for everything both cpy and gpu. mimics my engine a
// little. i have an elaborate system for managing memory, message me on twitter
// if you need my memory classes. (i currently close sourced my engine)
class Mine {

public:
  static Mine &Get();
  static void Destroy();

  Mine(const Mine &) = delete;
  Mine &operator=(const Mine &) = delete;
  Mine(Mine &&) = delete;
  Mine &operator=(Mine &&) = delete;

public:
  Buffer *AllocGpuBuffer(const BufferConfig &) const {
    // allocates and returns some memory buffer based on the config info
    // provided in the params above
    return vertexBufferLine; // just as an example
  }

private:
  Mine() { COFFEE_PRINT("Mine Created") };
  ~Mine() { COFFEE_PRINT("Mine Destroyed") };

private:
  static Mine *s_instance;

  Buffer *vertexBufferLine{};
  Buffer *indexBufferLine{};
  Buffer *transformBufferLine{};
  Buffer *lightsBufferLine{};
  // can be a templated Buffer for custom type
  Buffer *customBufferLine0{};
  Buffer *customBufferLine1{};

  Texture *colorFullScreen{};
  Texture *normalFullScreen{};
  Texture *roughnessMetallicFullScreen{};
  // can be a templated Texture for custom type
  Texture *customFullScreen0{};
  Texture *customFullScreen1{};
};

// could be a singleton depending upon if you want it to manage actual memory.
// in my case i have a "memory mine" as above. that has the data
class Manager {
public:
  static const GpuSavedData &GetGpuData() { return s_gpuData; }

  static void CopyMeshRelatedDataToGPU(const std::byte *meshesData) {
    COFFEE_PRINT("Copied Meshes related data to the GPU");
  }
  static void CopyTransformsRelatedDataToGPU(const std::byte *transformsData) {
    COFFEE_PRINT("Copied Transforms data to the GPU memory");
  }
  static void CopyMaterialsDataToGPU(const std::byte *materialsData) {
    COFFEE_PRINT("Copied Materials data to the GPU memory")
  }

  // ... and so on...
private:
  inline static Mine &s_mine = Mine::Get();
  inline static GpuSavedData s_gpuData{};
};

} // namespace Memory
} // namespace Coffee

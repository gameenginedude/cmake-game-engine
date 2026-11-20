#pragma once

#include "Coffee/Logs.h"
#include <cstddef>
namespace Coffee {
namespace Gfx {

// creation info about the pass - like the info specific to the "paint layer"
// explained in the video
struct RenderPassInfo {};

// pipeline specific information, like which attachments to use, what
// portion/size of the screen should be painted on? and so on...
struct PipelineInfo {};

// ideally you'd wanna supply these to the pipeline (for some pipelines you can
// let the game developer supply these too!)
struct ShaderModule {
  const std::byte *vertexShader;   // compiled bytecode
  const std::byte *fragmentShader; // compiled bytecode
  // some other custom shaders maybe
};

class Renderer {
public:
  static Renderer &Get();
  static void Destroy();

  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;
  Renderer(Renderer &&) = delete;
  Renderer &operator=(Renderer &&) = delete;

  // this method was from my CMake course on YT (this demonstrated how you can
  // add vulkan-loaders to your project or something like that)
  void Init();

  void CreateRenderPass(const RenderPassInfo &) {
    COFFEE_PRINT("Render pass created");
  }
  void CreatePipeline(const ShaderModule &, const PipelineInfo &) {
    COFFEE_PRINT("Pipeline created");
  }
  // void IssueDrawCommandToGPU(const GPUSavedData *) {
  //   COFFEE_PRINT("Drawing frame as per the saved data");
  // }

private:
  Renderer();
  ~Renderer();

private:
  static Renderer *s_instance;
};

} // namespace Gfx
} // namespace Coffee

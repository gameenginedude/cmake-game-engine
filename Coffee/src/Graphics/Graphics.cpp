#include "Coffee/Graphics/Graphics.h"
#include "Coffee/Logs.h"
#include "Coffee/Renderer/Renderer.h"

namespace Coffee {
namespace Gfx {
Graphics *Graphics::s_instance = new Graphics();

Graphics::Graphics() { COFFEE_PRINT("Graphics Created"); }

Graphics::~Graphics() {
  Renderer::Destroy();
  COFFEE_PRINT("Graphics Destroyed");
}

void Graphics::Init() {
  m_renderer = &Renderer::Get();
  m_renderer->Init();
}

void Graphics::InitializeGraphics(OSWindow *window,
                                  const GraphicsConfig &gfxConf) {
  // takes in window info, graphics config as set by the game developer, and
  // initializes required render passes, pipelines, shaders, etc

  // below dumb example initializes a basic material color pass
  ShaderModule basicMaterialShading = {.vertexShader = VertexShader,
                                       .fragmentShader = FragmentShader};

  PipelineInfo basicMaterialPipeline = {
      // like some info about the material/surface properties specific to
      // pipeline type
  };

  RenderPassInfo basicMaterialPass = {
      // like some info about the attachments (like "canvas" information in
      // terms of painting analogy)
  };

  m_renderer.CreatePipeline(basicMaterialShading, basicMaterialPipeline);
  m_renderer.CreateRenderPass(basicMaterialPass);

  std::cout << "basic material render pass created, pipelines ready!" << '\n';
  // similarly write your own pipelines / renderpasses as per your need.
}

void Graphics::PaintFrame() {
  m_renderer.IssueDrawCommandToGPU(m_memory.GetGPUDataPtr());
  std::cout << "All the scene data saved in the GPU memory is painted on screen"
               "according to the Renderpasses and Pipelines defined by the "
               "developer"
            << '\n';
};

void Graphics::RegisterScene(const Scene &scene) {
  // registers scene (copies all the scene specific data to GPU memory to get
  // ready for painting)
  //
  // in the below dumb examples, assume some data handle instead of nullptr,
  // pointing to data in the Scene
  m_memory.CopyMeshRelatedDataToGPU(nullptr);
  m_memory.CopyTransformsRelatedDataToGPU(nullptr);
  m_memory.CopyMaterialsDataToGPU(nullptr);
}

Graphics &Graphics::Get() { return *s_instance; }

void Graphics::Destroy() {
  if (s_instance)
    delete s_instance;
  else {
    // throw error, log
  }
}
} // namespace Gfx
} // namespace Coffee

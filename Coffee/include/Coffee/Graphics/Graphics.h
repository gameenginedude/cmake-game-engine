#pragma once

#include "Coffee/Graphics/Scene.h"

namespace Coffee {
namespace Gfx {

class Renderer;
class OSWindow;

// NOTE: graphics systems design can be vastly different among different
// engines. this is just a very dumb example.

struct GraphicsConfig {
  // user defined config, very surface level, like which materials should
  // render? setting individual properties of materials, manage textures, high
  // level rendering settings
};

class Graphics {
public:
  static Graphics &Get();
  static void Destroy();

  Graphics(const Graphics &) = delete;
  Graphics &operator=(const Graphics &) = delete;
  Graphics(Graphics &&) = delete;
  Graphics &operator=(Graphics &&) = delete;

  void Init();

private:
  Graphics();
  ~Graphics();

private:
  // 3 methods below assume a simple setup
  //
  //  initialize graphics, where client
  // specifies window, gfxConf like all the rendering settings (including
  // renderpasses to use, custom shaders for some peipelines etc)
  void InitializeGraphics(OSWindow *window, const GraphicsConfig &gfxConf);
  // registers the scene (sets the active scene that needs to be painted in the
  // current frame). probably in the gfxConfig, they can set which camera(s) to
  // use etc
  void RegisterScene(const Scene &scene);
  // paints frame based on the settings above
  void PaintFrame();

private:
  Renderer *m_renderer = nullptr;
  // Memory m_memory{};

  static Graphics *s_instance;
};

} // namespace Gfx
} // namespace Coffee

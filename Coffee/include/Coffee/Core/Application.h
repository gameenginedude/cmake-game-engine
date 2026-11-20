#pragma once

#include "Coffee/Core/CoreDefs.h"
#include "Coffee/Graphics/Graphics.h"
#include <functional>
#include <stdexcept>

namespace Coffee {
namespace Core {

class Window;
class Time;

struct AppContext {
  Window *window{};
  Gfx::Graphics *graphics{};
};

class Application {
public:
  using OnUpdateFunc = std::function<void(const FrameData &)>;

public:
  static Application &Get();
  static void Destroy();

  Application(const Application &) = delete;
  Application &operator=(const Application &) = delete;
  Application(Application &&) = delete;
  Application &operator=(Application &&) = delete;

  void Start(const OnUpdateFunc &onUpdate);
  void Stop();

  inline void GetContext(AppContext &ctx) const {
    if (!m_window || !m_graphics) {
      throw std::runtime_error("Window or Graphics nullptr");
    }

    ctx.window = m_window;
    ctx.graphics = m_graphics;
  }

private:
  Application();
  ~Application();

  void StartGame(const OnUpdateFunc &onUpdate);
  void StopGame();

private:
  bool m_isGameStillRunning = false;

  Window *m_window{};
  Time *m_time{};
  Gfx::Graphics *m_graphics{};
  static Application *s_instance;
};

} // namespace Core
} // namespace Coffee

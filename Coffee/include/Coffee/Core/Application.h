#pragma once

namespace Core {
class Application {
public:
  static Application &Get();
  static void Destroy();

  Application(const Application &) = delete;
  Application &operator=(const Application &) = delete;
  Application(Application &&) = delete;
  Application &operator=(Application &&) = delete;

private:
  Application() {}
  ~Application() = default;

private:
  static Application *s_instance;
};

} // namespace Core

#include "Coffee/Core/Application.h"
#include "Coffee/Core/Window.h"

namespace Core {
Application *Application::s_instance = nullptr;

Application &Application::Get() {
  if (!s_instance) {
    s_instance = new Application();
    Window win = Window();
  }
  return *s_instance;
}

void Application::Destroy() {
  if (s_instance)
    delete s_instance;
  else {
    // throw error, log
  }
}

} // namespace Core

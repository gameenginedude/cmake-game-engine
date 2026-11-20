#include "Coffee/Core/Application.h"
#include "Coffee/Core/Time.h"
#include "Coffee/Core/Window.h"
#include "Coffee/Logs.h"

namespace Coffee {
namespace Core {
Application *Application::s_instance = new Application();

Application::Application() { COFFEE_PRINT("Application Created"); }

Application::~Application() {
  Window::Destroy();
  COFFEE_PRINT("Application Destroyed");
}

void Application::Start(const OnUpdateFunc &onUpdate) {
  // window stuff
  m_window = &Window::Get();
  m_window->Create();

  StartGame(onUpdate);
}
void Application::Stop() { StopGame(); }

void Application::StartGame(const OnUpdateFunc &onUpdate) {
  m_isGameStillRunning = true;
  while (m_isGameStillRunning) {
    // The Game Loop.
    // Update all the data specific to the frame, and then paint the frame

    FrameData timeData = m_time->UpdateFrameTime();
    // std::cout << '\n';
    // std::cout << "Framerate (fps): " << 1.0 / timeData.deltaS << '\n';
    // std::cout << "Elapsed time: " << timeData.elapsedTimeS << " seconds\n";

    // let the game dev use this area
    //
    onUpdate(timeData);
  }
}
void Application::StopGame() { m_isGameStillRunning = false; }

Application &Application::Get() { return *s_instance; }

void Application::Destroy() {
  if (s_instance)
    delete s_instance;
  else {
    // throw error, log
  }
}

} // namespace Core
} // namespace Coffee

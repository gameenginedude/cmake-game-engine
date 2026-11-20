

#include "Coffee/Core/Time.h"

namespace Coffee {
namespace Core {
Time *Time::s_instance = new Time();

FrameData Time::UpdateFrameTime() {
  auto currentTime = Clock::now();
  auto elapsedS = std::chrono::duration<double, std::chrono::seconds::period>(
                      currentTime - m_startTime)
                      .count();
  auto deltaS = std::chrono::duration<double, std::chrono::seconds::period>(
                    currentTime - m_prevFrameTime)
                    .count();
  m_prevFrameTime = currentTime;
  return FrameData{elapsedS, deltaS};
}

} // namespace Core

} // namespace Coffee

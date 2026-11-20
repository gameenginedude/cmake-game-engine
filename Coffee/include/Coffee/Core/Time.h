#pragma once

#include "Coffee/Core/CoreDefs.h"
#include "Coffee/Logs.h"
#include <chrono>

namespace Coffee {
namespace Core {

using Clock = std::chrono::high_resolution_clock;
using TimeStamp = std::chrono::time_point<Clock>;
using SecondsPeriod = std::chrono::seconds::period;
template <typename T>
using getDuration = std::chrono::duration<T, SecondsPeriod>;

class Time {
  using Clock = std::chrono::high_resolution_clock;
  using TimeStamp = std::chrono::time_point<Clock>;

public:
  static Time &Get() { return *s_instance; }
  static void Destroy() {
    if (s_instance) {
      delete s_instance;
    }
    s_instance = nullptr;
  }

  Time(const Time &) = delete;
  Time &operator=(const Time &) = delete;
  Time(Time &&) = delete;
  Time &operator=(Time &&) = delete;

private:
  friend class Application;

  FrameData UpdateFrameTime();
  Time() { COFFEE_PRINT("Time Created"); }
  ~Time() { COFFEE_PRINT("Time Destroyed"); };

private:
  const TimeStamp m_startTime = Clock::now();
  TimeStamp m_prevFrameTime = m_startTime;

  static Time *s_instance;
};

} // namespace Core
} // namespace Coffee

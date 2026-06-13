#pragma once

#include <iostream>

namespace Core {
class Window {
public:
  Window() { std::cout << "WINDOW CREATED" << '\n'; }
};
} // namespace Core

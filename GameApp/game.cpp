#include "Coffee/Core/Application.h"
#include <iostream>
#include <ostream>

int main() {
    std::cout << "I'm inside game application" << std::endl;
  Core::Application &appInstance = Core::Application::Get();

  return 0;
}

#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

namespace Core {
class Window {
public:
  Window() {
    std::cout << "WINDOW CREATED" << '\n';

    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
      std::cout << "Error initing glfw" << '\n';

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
      glfwTerminate();
      // throw err
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
      /* Swap front and back buffers */
      glfwSwapBuffers(window);

      /* Poll for and process events */
      glfwPollEvents();
    }

    glfwTerminate();
  }
};
} // namespace Core

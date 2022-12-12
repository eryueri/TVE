#include "Platform/linux/LinuxWindow.hh"

#include <GLFW/glfw3.h>

#include "Events/Event.hh"

#include "Events/KeyEvents.hh"
#include "Events/MouseEvents.hh"
#include "Events/WindowEvents.hh"

namespace TVE {
#define MAX_WINDOWS_ALLOWED (uint32_t)4
  static uint32_t windowNum = 0;
  LinuxWindow::LinuxWindow(const WindowProperties& prop) {
    initData(prop);

    if (windowNum == MAX_WINDOWS_ALLOWED) {
      throw std::runtime_error("creating too much windows!");
    }

    if (windowNum == 0) {
      glfwInit();
    }

    _window = glfwCreateWindow(_data.width, _data.height, _data.title.c_str(), nullptr, nullptr);

    glfwSetWindowUserPointer(_window, (void*)&_data);

    glfwSetWindowSizeCallback(
        _window, 
        [](GLFWwindow* window, int width, int height) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
          WindowResize event(width, height);
          data->func(event);
        });

    glfwSetWindowPosCallback(
        _window, 
        [](GLFWwindow* window, int xpos, int ypos) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
          WindowMove event{xpos, ypos};
          data->func(event);
        });

    glfwSetWindowFocusCallback(
        _window, 
        [](GLFWwindow* window, int focused) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
          if (focused) {
            WindowFocus event{};
            data->func(event);
          } else {
            WindowUnFocus event{};
            data->func(event);
          }
        });

    glfwSetWindowCloseCallback(
        _window, 
        [](GLFWwindow* window) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
          WindowClose event{};
          data->func(event);
        });

    glfwSetKeyCallback(
        _window, 
        [](GLFWwindow* window, int key, int scancode, int action, int mods) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
          
          switch(action) {
          case(GLFW_PRESS): {
            KeyPressed event(key);
            data->func(event);
          } break;
          case(GLFW_RELEASE): {
            KeyReleased event(key);
            data->func(event);
          } break;
          case(GLFW_REPEAT): {
            KeyRepeated event(key);
            data->func(event);
          } break;
          default: break;
          }
        });

    glfwSetCursorPosCallback(
        _window, 
        [](GLFWwindow* window, double xpos, double ypos) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
          MouseMoved event{(float)xpos, (float)ypos};
          data->func(event);
        });

    glfwSetMouseButtonCallback(
        _window, 
        [](GLFWwindow* window, int button, int action, int mods) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

          switch(action) {
          case(GLFW_PRESS): {
            MouseButtonPressed event(button);
            data->func(event);
          } break;
          case(GLFW_RELEASE): {
            MouseButtonReleased event(button);
            data->func(event);
          } break;
          default: break;
          }
        });

    glfwSetScrollCallback(
        _window, 
        [](GLFWwindow* window, double xoffset, double yoffset) {
          WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

          MouseScroll event{(float)xoffset, (float)yoffset};

          data->func(event);
        });

    ++windowNum;
  }

  LinuxWindow::~LinuxWindow() {

  }

  uint32_t LinuxWindow::getWidth() const {
    return _data.width;
  }

  uint32_t LinuxWindow::getHeight() const {
    return _data.height;
  }

  void LinuxWindow::onUpdate() {
    glfwPollEvents();
  }

  void LinuxWindow::setEventCallback(const EventCallbackFunc& func) {
    _data.func = func;
  }

  void LinuxWindow::initData(const WindowProperties& prop) {
    _data.width = prop.width;
    _data.height = prop.height;
    _data.offsetx = prop.offsetx;
    _data.offsety = prop.offsety;
    _data.title = prop.title;
  }

  void LinuxWindow::cleanup() {
    --windowNum;
    if (windowNum == 0) {
      glfwTerminate();
    }
  }
}

#include "Platform/linux/TVELinuxWindow.hh"

#include <GLFW/glfw3.h>

#include "Events/Event.hh"

namespace TVE {
  TVELinuxWindow::TVELinuxWindow(const WindowProperties& prop) {
    initData(prop);

    _window = glfwCreateWindow(_data.width, _data.height, _data.title.c_str(), nullptr, nullptr);

    glfwSetKeyCallback(
        _window, 
        [](GLFWwindow* window, int key, int scancode, int action, int mods) {
          
        });
  }

  uint32_t TVELinuxWindow::getWidth() const {
    return _data.width;
  }

  uint32_t TVELinuxWindow::getHeight() const {
    return _data.height;
  }

  void TVELinuxWindow::onUpdate() {

  }

  void TVELinuxWindow::setEventCallback() {

  }

  void TVELinuxWindow::initData(const WindowProperties& prop) {
    _data.width = prop.width;
    _data.height = prop.height;
    _data.offsetx = prop.offsetx;
    _data.offsety = prop.offsety;
    _data.title = prop.title;
  }
}

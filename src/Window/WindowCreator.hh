#pragma once

#include "Window.hh"

namespace TVE {
  class WindowCreator {
  public:
    static Window* CreateWindow(const WindowProperties& prop);
  };
}

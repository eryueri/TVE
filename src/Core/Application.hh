#pragma once

#include "Window/Window.hh"

namespace TVE {
  class Application {
  public:
    Application();
    virtual ~Application();
    void run();
  private:
    void init();
    void cleanup();
  private:
    bool _running;
    Window* _window;
  };
}

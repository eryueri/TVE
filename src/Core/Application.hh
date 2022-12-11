#pragma once

#include "Window/Window.hh"

namespace TVE {
  class Application {
  public:
    Application();
    virtual ~Application();
    void run();
    void onEvent(Event& e);
  private:
    bool _running = false;
    std::unique_ptr<Window> _window;
  };
}

#pragma once

#include "Window/Window.hh"
#include "LayerStack.hh"
#include "Core/Logger.hh"

namespace TVE {
  class WindowClose;
  class Application {
  public:
    Application();
    virtual ~Application();
    void run();
    void onEvent(Event& e);
    void onWindowClose(WindowClose& e);
  private:
    bool _running = false;
    std::unique_ptr<Window> _window;
    LayerStack _stack;
  };
}

#define BIND_ON_EVENT_FUNCTION(func) std::bind(&func, this, std::placeholders::_1)

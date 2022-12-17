#include "Application.hh"

#include "Events/Event.hh"
#include "Events/WindowEvents.hh"
#include "Events/KeyEvents.hh"
#include "Events/MouseEvents.hh"
#include "Core/Logger.hh"
#include "Window/WindowCreator.hh"

namespace TVE {
  Application::Application() {
    _window = std::unique_ptr<Window>(WindowCreator::CreateWindow(WindowProperties{}));
    _window->setEventCallback(BIND_ON_EVENT_FUNCTION(Application::onEvent));
  }

  Application::~Application() {

  }

  void Application::onEvent(Event& e) {
    EventDispatcher d{e};
    d.dispatch<WindowClose>(BIND_ON_EVENT_FUNCTION(Application::onWindowClose));

    for (auto layer : _stack) {
      layer->onEvent(e);
    }
  }

  void Application::onWindowClose(WindowClose& e) {
    TVE_CRITICAL("WINDOW CLOSED");
    _running = false;
  }

  void Application::run() {
    _running = true;
    while(_running) {
      _window->onUpdate();
    }
  }
}

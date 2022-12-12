#include "Application.hh"

#include "Events/Event.hh"
#include "Core/Logger.hh"
#include "Window/WindowCreator.hh"

namespace TVE {
  Application::Application() {
    _window = std::unique_ptr<Window>(WindowCreator::CreateWindow(WindowProperties{}));
    _window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
  }

  Application::~Application() {

  }

  void Application::onEvent(Event& e) {
    TVE_TRACE(e.verboseStr());
  }

  void Application::run() {
    _running = true;
    while(_running) {
      _window->onUpdate();
    }
  }
}

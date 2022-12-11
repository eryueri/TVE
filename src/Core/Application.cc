#include "Application.hh"

#include "spdlog/spdlog.h"
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
    Logger::ConsoleLog()->trace("event");
  }

  void Application::run() {
    _running = true;
    while(_running) {
      _window->onUpdate();
    }
  }
}

#include "Application.hh"

#include "Window/WindowCreator.hh"

namespace TVE {
  Application::Application() {
    init();

    _window = WindowCreator::CreateWindow();
  }

  Application::~Application() {

  }

  void Application::init() {

  }

  void Application::cleanup() {

  }

  void Application::run() {
    
  }
}

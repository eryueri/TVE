#include "Core/Logger.hh"
#include "Core/Application.hh"

int main() {
  TVE::Logger::Init();
  TVE::Application app;
  app.run();
}

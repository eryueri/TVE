#include "Core/Logger.hh"
#include "Core/Config.hh"

int main() {
  TVE::Logger::Init();

  try{
  TVE::Config::LoadSetting("./config/Debug.toml");
  TVE::Config::LoadSetting("thisisnotavalidpath");
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    throw std::runtime_error("haha");
  }
}

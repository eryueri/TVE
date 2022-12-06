#include "Logger.hh"
#include "Config.hh"

int main() {
  TVE::Logger::Init();

  TVE::Config::LoadSetting("./config/Debug.toml");
  TVE::Config::LoadSetting("thisisnotavalidpath");
}

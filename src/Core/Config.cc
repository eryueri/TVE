#include "Config.hh"

#include "pchTVE.hh"

#include "toml++/toml.h"

#include "Core/Logger.hh"
#include <spdlog/spdlog.h>

TVE::Config::LoadData TVE::Config::settings;

namespace TVE {
  void Config::LoadSetting(std::filesystem::path path) {
    if (!std::filesystem::exists(path)) {
      throw std::runtime_error("path does not exist!");
    }
    std::filesystem::directory_entry file(path);
    if (file.status().type() == std::filesystem::file_type::regular) {
      toml::parse_result parsedFile = toml::parse_file(path.string());
      bool vali = parsedFile["Debug"]["enableValidationLayer"].as_boolean();
      TVE::Logger::ConsoleLog()->info(vali);
    }
  }
}

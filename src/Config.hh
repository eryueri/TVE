#pragma once

#include "Settings/DebugSettings.hh"
#include "Settings/PathSettings.hh"
#include "Settings/EngineSettings.hh"

namespace TVE {
  class Config {
  public:
    static struct LoadData {
      DebugSettings debugSetting;
      PathSettings pathSetting;
      EngineSettings engineSetting;
    } settings;

    static void LoadSetting(std::filesystem::path path);

  private:
    Config() = default;
    ~Config() = default;
  };
}

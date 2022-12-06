#pragma once

#include <filesystem>

namespace TVE {
  struct PathSettings {
    std::filesystem::path rootPath = "./";
    std::filesystem::path resourcePath = "resource/";
  };
}

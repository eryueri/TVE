#pragma once

#include "pchTVE.hh"

namespace TVE {
  struct DebugSettings {
    enum class LogLevel : uint8_t {
      TRACE, 
      INFO, 
      WARN, 
      ERROR
    };
    bool enableValidationLayer = false;
    LogLevel logLevel = LogLevel::ERROR;
  };
}

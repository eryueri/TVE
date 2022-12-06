#pragma once

#include "pchTVE.hh"

namespace spdlog {
  class logger;
}

namespace TVE {
  class Logger {
  public:
    static void Init();
    static std::shared_ptr<spdlog::logger>& ConsoleLog() { return ConsoleLogger; }
  private:
    static std::shared_ptr<spdlog::logger> ConsoleLogger;
  };
}

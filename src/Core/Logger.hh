#pragma once

#include "pchTVE.hh"

#include <spdlog/spdlog.h>

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

#define TVE_TRACE(...) TVE::Logger::ConsoleLog()->trace(__VA_ARGS__)
#define TVE_INFO(...) TVE::Logger::ConsoleLog()->info(__VA_ARGS__)
#define TVE_WARN(...) TVE::Logger::ConsoleLog()->warn(__VA_ARGS__)
#define TVE_ERROR(...) TVE::Logger::ConsoleLog()->error(__VA_ARGS__)
#define TVE_CRITICAL(...) TVE::Logger::ConsoleLog()->critical(__VA_ARGS__)

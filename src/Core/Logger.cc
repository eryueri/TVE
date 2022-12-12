#include "Logger.hh"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace TVE {
  std::shared_ptr<spdlog::logger> Logger::ConsoleLogger;

  void Logger::Init() {
    auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    ConsoleLogger = std::make_shared<spdlog::logger>("TVE", sink);
    ConsoleLogger->set_pattern("%^[%T] %n: %v%$");
    ConsoleLogger->set_level(spdlog::level::trace);
    ConsoleLogger->flush_on(spdlog::level::trace);
  }
}

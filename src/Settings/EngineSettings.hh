#pragma once

#include <string>

namespace TVE {

  struct EngineSettings {
    enum PresentMode : uint8_t {
      FIFO,
      MAILBOX,
      IMMEDIATE,
      BEST_AVAILABALE
    };
    PresentMode presentMode = PresentMode::BEST_AVAILABALE;
    std::string appName = "myApp";
    std::string appEnginName = "No Engine";
    int gpuIndex = -1;
  };

};

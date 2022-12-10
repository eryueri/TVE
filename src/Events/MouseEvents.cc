#include "MouseEvents.hh"

namespace TVE {
  std::string MouseMoved::verboseStr() const {
    return "Mouse now moved to: (" + std::to_string(_x) + "," + std::to_string(_y);
  }
  std::string MouseScroll::verboseStr() const {
    return "Mouse scrolled x: " + std::to_string(_xoffset) + ", y: " + std::to_string(_yoffset);
  }
  std::string MouseButtonPressed::verboseStr() const {
    return "Mouse pressed: " + std::to_string(_button);
  }
  std::string MouseButtonReleased::verboseStr() const {
    return "Mouse released: " + std::to_string(_button);
  }
}

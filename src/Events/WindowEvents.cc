#include "WindowEvents.hh"

namespace TVE {
  std::string WindowResize::verboseStr() const {
    return "window resize to: width: " + std::to_string(_width) + ", height: " + std::to_string(_height) + "\n";
  }
  std::string WindowMove::verboseStr() const {
    return "window move to: (" + std::to_string(_x) + ", " + std::to_string(_y) + ")\n";
  }
  std::string WindowFocus::verboseStr() const {
    return "Focused to window!\n";
  }
  std::string WindowUnFocus::verboseStr() const {
    return "Window unfocused!\n";
  }
  std::string WindowClose::verboseStr() const {
    return "Window Closed!\n";
  }
}

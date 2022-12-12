#include "WindowEvents.hh"

namespace TVE {
  std::string WindowResize::verboseStr() const {
    return "window resize to: width: " + std::to_string(_width) + ", height: " + std::to_string(_height);
  }
  std::string WindowMove::verboseStr() const {
    return "window move to: (" + std::to_string(_x) + ", " + std::to_string(_y);
  }
  std::string WindowFocus::verboseStr() const {
    return "Focused to window!";
  }
  std::string WindowUnFocus::verboseStr() const {
    return "Window unfocused!";
  }
  std::string WindowClose::verboseStr() const {
    return "Window Closed!";
  }
}

#include "KeyEvents.hh"

namespace TVE {
  std::string KeyPressed::verboseStr() const {
    return "Pressed Key: " + std::to_string(_code);
  }
  std::string KeyReleased::verboseStr() const {
    return "Released Key: " + std::to_string(_code);
  }
  std::string KeyRepeated::verboseStr() const {
    return "Repeated Key: " + std::to_string(_code);
  }
}

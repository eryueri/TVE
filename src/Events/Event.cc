#include "Event.hh"

namespace TVE {
  uint8_t operator&(const EventCategory& a, const EventCategory& b) {
    return static_cast<uint8_t>(a) 
    & 
    static_cast<uint8_t>(b);
  }

  uint8_t operator&(const EventCategory& a, const uint8_t& b) {
    return static_cast<uint8_t>(a) 
    & 
    b;
  }

  uint8_t operator&(const uint8_t& a, const EventCategory& b) {
    return a 
    & 
    static_cast<uint8_t>(b);
  }

  uint8_t operator|(const EventCategory& a, const EventCategory& b) {
    return static_cast<uint8_t>(a) 
    | 
    static_cast<uint8_t>(b);
  }

  uint8_t operator|(const EventCategory& a, const uint8_t& b) {
    return static_cast<uint8_t>(a) 
    | 
    b;
  }

  uint8_t operator|(const uint8_t& a, const EventCategory& b) {
    return a 
    | 
    static_cast<uint8_t>(b);
  }

  template<typename T, typename F>
  bool EventDispatcher::dispatch(const F& func) const {
    if (T::getStaticType() == _event.getEventType()) {
      func(static_cast<T&>(_event));
      _event.handled = true;
      return true;
    }
    return false;
  }

  std::ostream& operator<<(std::ostream& os, const Event& e) {
    return os << e.verboseStr();
  }
}
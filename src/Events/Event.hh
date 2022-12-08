#pragma once

#include "pchTVE.hh"

namespace TVE {
  #define BIT(x) (1 << (x))
  enum class EventType : uint16_t {
    None = 0, 
    WindowResized, WindowClosed, WindowMoved, WindowFocused, WindowUnFocused, 
    KeyPresssed, KeyReleased, KeyRepeated, 
    MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScroll
  };
  enum class EventCategory : uint8_t {
    None = 0,
    Input = BIT(1), 
    Keyboard = BIT(2), 
    MouseMove = BIT(3), 
    MouseButton = BIT(4)
  };
  uint8_t operator&(const EventCategory& a, const EventCategory& b);
  uint8_t operator&(const EventCategory& a, const uint8_t& b);
  uint8_t operator&(const uint8_t& a, const EventCategory& b);
  uint8_t operator|(const EventCategory& a, const EventCategory& b);
  uint8_t operator|(const EventCategory& a, const uint8_t& b);
  uint8_t operator|(const uint8_t& a, const EventCategory& b);
  class Event {
  public:
    bool handled = false;
    virtual EventType getEventType() const = 0;
    virtual uint8_t getEventCategoryFlags() const = 0;
    virtual const char* getName() const = 0;
    virtual std::string verboseStr() const { return getName(); }
  };
  class EventDispatcher {
  public:
    EventDispatcher(Event& e) 
      : _event(e) {}
    template<typename T, typename F>
    bool dispatch(const F& func) const;
  private:
    Event& _event;
  };
  std::ostream& operator<<(std::ostream& os, const Event& e);
}
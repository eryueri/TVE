#pragma once

#include "pchTVE.hh"

namespace TVE {
  #define BIT(x) (1 << (x))
  enum class EventType : uint16_t {
    None = 0, 
    WindowResize, WindowMove, WindowFocus, WindowUnFocus, WindowClose, 
    KeyPressed, KeyReleased, KeyRepeated, 
    MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScroll
  };
  enum class EventCategory : uint8_t {
    None = 0,
    Window = BIT(1),
    Input = BIT(2), 
    Keyboard = BIT(3), 
    MouseMove = BIT(4), 
    MouseButton = BIT(5)
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
    bool isInCategory(const EventCategory& category) {
      return getEventCategoryFlags() & category;
    }
  };
#define EVENT_CLASS_TYPE(type) \
  static EventType getStaticType() { return EventType::type; } \
  virtual EventType getEventType() const override { return getStaticType(); } \
  virtual const char* getName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) \
  virtual uint8_t getEventCategoryFlags() const override { return category; }
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

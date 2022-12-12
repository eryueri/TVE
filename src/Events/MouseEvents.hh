#pragma once

#include "Event.hh"

namespace TVE {
  class MouseMoved : public Event {
  public:
    float _x;
    float _y;

    MouseMoved(float x, float y)
      : _x(x), _y(y) {}
    
    EVENT_CLASS_TYPE(MouseMoved);
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::MouseMove);

    std::string verboseStr() const override;
  };

  class MouseScroll : public Event {
  public:
    float _xoffset;
    float _yoffset;

    MouseScroll(float xoffset, float yoffset)
      : _xoffset(xoffset), _yoffset(yoffset) {}
    
    EVENT_CLASS_TYPE(MouseMoved);
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::MouseMove);

    std::string verboseStr() const override;
  };

  class MouseButtonPressed : public Event {
  public:
    uint8_t _button;

    MouseButtonPressed(uint8_t button)
      : _button(button) {}

    EVENT_CLASS_TYPE(MouseButtonPressed);
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::MouseButton);

    std::string verboseStr() const override;
  };

  class MouseButtonReleased : public Event {
  public:
    uint8_t _button;

    MouseButtonReleased(uint8_t button)
      : _button(button) {}

    EVENT_CLASS_TYPE(MouseButtonReleased);
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::MouseButton);

    std::string verboseStr() const override;
  };
}

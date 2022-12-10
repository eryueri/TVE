#pragma once

#include "Event.hh"

namespace TVE {
  class WindowResize : public Event {
  public:
    int _width;
    int _height;

    WindowResize(int width, int height)
      : _width(width), _height(height) {}

    EVENT_CLASS_TYPE(WindowResize);
    EVENT_CLASS_CATEGORY(static_cast<uint8_t>(EventCategory::Window));

    std::string verboseStr() const override;
  };
  class WindowMove : public Event {
  public:
    int _x;
    int _y;

    WindowMove(int x, int y)
      : _x(x), _y(y) {}

    EVENT_CLASS_TYPE(WindowResize);
    EVENT_CLASS_CATEGORY(static_cast<uint8_t>(EventCategory::Window));

    std::string verboseStr() const override;
  };
  class WindowFocus : public Event {
  public:
    WindowFocus() {}

    EVENT_CLASS_TYPE(WindowResize);
    EVENT_CLASS_CATEGORY(static_cast<uint8_t>(EventCategory::Window));

    std::string verboseStr() const override;
  };
  class WindowUnFocus : public Event {
  public:
    WindowUnFocus() {}

    EVENT_CLASS_TYPE(WindowResize);
    EVENT_CLASS_CATEGORY(static_cast<uint8_t>(EventCategory::Window));

    std::string verboseStr() const override;
  };
  class WindowClose : public Event {
  public:
    WindowClose() {}

    EVENT_CLASS_TYPE(WindowResize);
    EVENT_CLASS_CATEGORY(static_cast<uint8_t>(EventCategory::Window));

    std::string verboseStr() const override;
  };
}

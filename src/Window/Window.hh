#pragma once

#include "pchTVE.hh"

namespace TVE {
  class Event;
  struct WindowProperties {
    uint32_t width; 
    uint32_t height;
    uint32_t offsetx;
    uint32_t offsety;
    std::string title;
    WindowProperties(
        const uint32_t& width = 1280, const uint32_t& height = 960, 
        const uint32_t& offsetx = 320, const uint32_t& offsety = 60, 
        const std::string& title = "TVE") 
      : width(width), height(height), offsetx(offsetx), offsety(offsety), title(title) {}
  };
  class Window {
  public:
    using EventCallbackFunc = std::function<void(Event&)>;

    virtual uint32_t getWidth() const = 0;
    virtual uint32_t getHeight() const = 0;
    virtual void onUpdate() = 0;
    virtual void setEventCallback(const EventCallbackFunc& func) = 0;
  };
}

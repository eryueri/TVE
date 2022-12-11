#pragma once

#include "Window/Window.hh"

struct GLFWwindow;

namespace TVE {
  class LinuxWindow : public Window {
  public:
    LinuxWindow() = delete;
    LinuxWindow(const WindowProperties& prop);
    ~LinuxWindow();

    virtual uint32_t getWidth() const override;
    virtual uint32_t getHeight() const override;
    virtual void onUpdate() override;
    virtual void setEventCallback(const EventCallbackFunc& func) override;
  private:
    void initData(const WindowProperties& prop);
    void cleanup();
  private:
    GLFWwindow* _window;

    struct WindowData {
      uint32_t width, height;
      uint32_t offsetx, offsety;
      std::string title;
      EventCallbackFunc func;
    };

    WindowData _data;
  };
}

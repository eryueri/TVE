#pragma once

#include "Core/TVEWindow.hh"

struct GLFWwindow;

namespace TVE {
  class TVELinuxWindow : public TVEWindow {
  public:
    TVELinuxWindow(const WindowProperties& prop);

    virtual uint32_t getWidth() const override;
    virtual uint32_t getHeight() const override;
    virtual void onUpdate() override;
    virtual void setEventCallback() override;
  private:
    void initData(const WindowProperties& prop);
    void clean();
  private:
    GLFWwindow* _window;

    struct WindowData {
      uint32_t width, height;
      uint32_t offsetx, offsety;
      std::string title;
    };

    WindowData _data;
  };
}

#include "TVEWindow.hh"

#include "Events/Event.hh"

namespace TVE {
  TVEWindow* TVEWindow::CreateWindow(const WindowProperties& prop) {
#if defined(TVE_WINODWS_PLATFORM)
    return new TVEWindowsWindow(prop);
#elif defined(TVE_LINUX_PLATFORM)
    return new TVELinuxWindow(prop);
#else
    return nullptr;
#endif
  }
}

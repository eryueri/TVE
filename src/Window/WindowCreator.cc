#include "WindowCreator.hh"

#if defined(TVE_WINDOWS_PLATFORM)
  #include "Platform/windows/WindowsWindow.hh"
#elif defined(TVE_LINUX_PLATFORM)
  #include "Platform/linux/LinuxWindow.hh"
#endif

namespace TVE {
  Window* WindowCreator::CreateWindow() {
#if defined(TVE_WINDOWS_PLATFORM)
    return WindowsWindow{};
#elif defined(TVE_LINUX_PLATFORM)
    return LinuxWindow{};
#endif
    return nullptr;
  }
}

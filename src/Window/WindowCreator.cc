#include "WindowCreator.hh"

#include "Macros.hh"

#if defined(TVE_WINDOWS_PLATFORM)
  #include "Platform/windows/WindowsWindow.hh"
#elif defined(TVE_LINUX_PLATFORM)
  #include "Platform/linux/LinuxWindow.hh"
#endif

namespace TVE {
  Window* WindowCreator::CreateWindow(const WindowProperties& prop) {
#if defined(TVE_WINDOWS_PLATFORM)
    return new WindowsWindow{prop};
#elif defined(TVE_LINUX_PLATFORM)
    return new LinuxWindow{prop};
#endif
    return nullptr;
  }
}

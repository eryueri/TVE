
if(NOT TARGET glfw3)
  find_package(glfw3 REQUIRED)
endif()

if(NOT TARGET Vulkan)
  find_package(Vulkan REQUIRED)
endif()

if(NOT TARGET spdlog)
  find_package(spdlog REQUIRED)
endif()

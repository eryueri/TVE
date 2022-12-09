if (NOT TARGET Vulkan::Vulkan)
  set(VULKAN_DIR $ENV(VK_SDK_PATH))
  set(VULKAN_INCLUDE_DIR "${VULKAN_DIR}/Include")
  set(VULKAN_LIB "${VULKAN_DIR}/Lib/vulkan-1.lib")
  add_library(Vulkan::Vulkan STATIC IMPORTED GLOBAL)
  set_target_properties(Vulkan::Vulkan
  PROPERTIES
  IMPORTED_LOCATION ${VULKAN_LIB}
  INTERFACE_INCLUDE_DIRECTORIES ${VULKAN_INCLUDE_DIR})
endif()

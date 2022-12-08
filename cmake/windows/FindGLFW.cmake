if (NOT TARGET glfw3)
  set(GLFW_DIR "E:/Lib/glfw-3.3.8.bin.WIN64")
  set(GLFW_LIB "${GLFW_DIR}/lib-vc2022")
  set(GLFW_INCLUDE_DIR "${GLFW_DIR}/include")
  add_library(glfw SHARED IMPORTED GLOBAL)
  set(GLFW_IMPLIB
  "${GLFW_LIB}/glfw3.lib"
  "${GLFW_LIB}/glfw3_mt.lib"
  "${GLFW_LIB}/glfw3dll.lib")
  set_target_properties(glfw
  PROPERTIES
  IMPORTED_LOCATION "${GLFW_LIB}/glfw3.dll"
  IMPORTED_IMPLIB "${GLFW_LIB}/glfw3.lib"
  IMPORTED_IMPLIB "${GLFW_LIB}/glfw3_mt.lib"
  IMPORTED_IMPLIB "${GLFW_LIB}/glfw3dll.lib"
  INTERFACE_INCLUDE_DIRECTORIES "${GLFW_INCLUDE_DIR}")
endif()

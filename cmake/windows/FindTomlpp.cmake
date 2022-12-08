if (NOT TARGET tomlplusplus::tomlplusplus)
  set(TOMLPP_INCLUDE_DIR "E:/Lib/tomlplusplus-3.2.0/include")
  add_library(tomlplusplus INTERFACE)
  set_target_properties(tomlplusplus
  PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${TOMLPP_INCLUDE_DIR}")
endif()
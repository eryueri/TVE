if (NOT TARGET spdlog::spdlog)
  set(SPDLOG_DIR "E:/Lib/spdlog")
  set(SPDLOG_LIB "${SPDLOG_DIR}/build/Release/spdlog.lib")
  set(SPDLOG_INCLUDE_DIR "${SPDLOG_DIR}/include")
  add_library(spdlog::spdlog STATIC IMPORTED GLOBAL)
  set_target_properties(spdlog::spdlog
    PROPERTIES
    IMPORTED_LOCATION "${SPDLOG_LIB}"
    INTERFACE_INCLUDE_DIRECTORIES "${SPDLOG_INCLUDE_DIR}")
endif()

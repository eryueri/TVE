aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}
  SUB_SOURCE_FILES)

add_subdirectory(./Core)
add_subdirectory(./Events)

set(SOURCE_FILES
  ${CORE_SOURCE_FILES}
  ${EVENT_SOURCE_FILES}
  ${SUB_SOURCE_FILES}
  PARENT_SCOPE)

set(PCH_HEADER
  "${CMAKE_CURRENT_SOURCE_DIR}/pchTVE.hh"
  PARENT_SCOPE)

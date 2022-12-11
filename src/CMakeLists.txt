aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}
  SUB_SOURCE_FILES)

add_subdirectory(./Core)
add_subdirectory(./Events)
add_subdirectory(./Window)
add_subdirectory(./Platform)

set(SOURCE_FILES
  ${CORE_SOURCE_FILES}
  ${EVENT_SOURCE_FILES}
  ${WINDOW_SOURCE_FILES}
  ${PLATFORM_SOURCE_FILES}
  ${SUB_SOURCE_FILES}
  PARENT_SCOPE)

# accroding to the test below this method of setting SOURCE_FILES
# will cause a lot of duplication, but currently i dont want to 
# explicitly write all the filenames, so i will leave it.
# although duplication seems not to cause any compile problem
# but i still feel very bad at the dupliction, so i write these
# lines of comment to remind me to fix it one day
# message(${CORE_SOURCE_FILES})
# message(${EVENT_SOURCE_FILES})

set(PCH_HEADER
  "${CMAKE_CURRENT_SOURCE_DIR}/pchTVE.hh"
  PARENT_SCOPE)

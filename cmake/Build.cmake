if(WIN32)
  add_library(TVE STATIC ${SOURCE_FILES})

  target_precompile_headers(TVE
    PRIVATE
    ${PCH_HEADER})

  target_link_libraries(TVE
    PRIVATE
    glfw
    spdlog::spdlog
    tomlplusplus)

  add_executable(main
    main.cc)

  target_link_libraries(main
    PRIVATE
    TVE)

elseif(UNIX)
  add_library(TVE SHARED ${SOURCE_FILES})

  target_precompile_headers(TVE
    PRIVATE
    ${PCH_HEADER})

  target_link_libraries(TVE
    PRIVATE
    glfw
    PUBLIC
    spdlog::spdlog)

  add_executable(main
    main.cc)

  target_link_libraries(main
    PRIVATE
    TVE)
endif()

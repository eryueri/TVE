cmake_minimum_required(VERSION 3.8)

project(TVE-trash-vulkan-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/FindPkg.cmake)

include_directories(
  deps/
  include/
  src/)

add_subdirectory(./src)

add_library(TVE SHARED ${SOURCE_FILES})

target_precompile_headers(TVE
  PRIVATE
  ${PCH_HEADER})

target_link_libraries(TVE
  PRIVATE
  glfw
  spdlog::spdlog)

add_executable(main
  main.cc)

target_link_libraries(main
  PRIVATE
  TVE)

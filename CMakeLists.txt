cmake_minimum_required(VERSION 3.8)

include(cmake/Platform.cmake)

project(TVE-trash-vulkan-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/FindPkg.cmake)

include_directories(
  deps/
  include/
  src/)

add_subdirectory(./src)

include(cmake/Build.cmake)

cmake_minimum_required(VERSION 3.16)
project(ShrinkMorphGUI)

set(GLFW_USE_STATIC ON)

find_package(OpenGL REQUIRED)
find_package(glfw CONFIG REQUIRED)
message(STATUS "glfw package found: ${glfw_DIR}")
find_package(imgui CONFIG REQUIRED)

add_executable(ShrinkMorphGUI
  main.cpp
  imgui_backends/imgui_impl_glfw.cpp
  imgui_backends/imgui_impl_opengl3.cpp
)

target_include_directories(ShrinkMorphGUI PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/gui/imgui_backends
)

target_link_libraries(ShrinkMorphGUI PRIVATE
  shrink_morph
  glfw
  imgui::imgui
  OpenGL::GL
)

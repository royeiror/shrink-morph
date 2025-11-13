cmake_minimum_required(VERSION 3.16)
project(ShrinkMorphGUI)

find_package(OpenGL REQUIRED)
set(GLFW_USE_STATIC ON)
find_package(glfw3 CONFIG REQUIRED)
message(STATUS "glfw3 package found: ${glfw3_DIR}")
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

# Check if glfw3 target exists
if(TARGET glfw3)
  target_link_libraries(ShrinkMorphGUI PRIVATE glfw3)
else()
  message(WARNING "glfw3 target not found, falling back to PkgConfig::glfw3")
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(GLFW REQUIRED glfw3)
  target_link_libraries(ShrinkMorphGUI PRIVATE ${GLFW_LIBRARIES})
  target_include_directories(ShrinkMorphGUI PRIVATE ${GLFW_INCLUDE_DIRS})
endif()

target_link_libraries(ShrinkMorphGUI PRIVATE
  shrink_morph
  imgui::imgui
  OpenGL::GL
)

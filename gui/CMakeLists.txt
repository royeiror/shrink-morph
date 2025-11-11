find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
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
  glfw3
  imgui::imgui
  OpenGL::GL
)

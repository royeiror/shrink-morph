find_package(OpenGL REQUIRED)
find_package(glfw CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(ShrinkMorphGUI main.cpp)

target_include_directories(ShrinkMorphGUI PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(ShrinkMorphGUI PRIVATE shrink_morph glfw imgui::imgui OpenGL::GL)

find_package(OpenGL REQUIRED)

add_executable(ShrinkMorphGUI main.cpp)
target_include_directories(ShrinkMorphGUI PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(ShrinkMorphGUI PRIVATE shrink_morph glfw OpenGL::GL)

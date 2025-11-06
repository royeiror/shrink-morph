#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include "shrink_morph_app.h"  // Include core logic

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Shrink Morph GUI", NULL, NULL);
    glfwMakeContextCurrent(window);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Shrink Morph Controls");
        static char meshPath[256] = "data/beetle.obj";
        ImGui::InputText("Mesh Path", meshPath, IM_ARRAYSIZE(meshPath));
        if (ImGui::Button("Run Shrink Morph")) {
            shrink_morph::run(meshPath);  // Call core logic
        }
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

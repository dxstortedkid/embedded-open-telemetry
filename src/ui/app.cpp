#include "eot/ui/app.hpp"
#include <cmath>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"

namespace eot::ui {

App::App() = default;

App::~App() {
    ImPlot::DestroyContext();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    if (window_) glfwDestroyWindow(window_);
    glfwTerminate();
}

bool App::init(int width, int height, const char* title) {
    if (!glfwInit()) return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window_) return false;

    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window_, true);
    ImGui_ImplOpenGL3_Init("#version 130");
    return true;
}

void App::run() {
    while (!glfwWindowShouldClose(window_)) {
        glfwPollEvents();

        float dt = ImGui::GetIO().DeltaTime;
        elapsed_time_ += dt;

        if (control_view_.is_streaming()) {
            float freq = control_view_.get_frequency();
            float v1 = 10.0f * std::sin(elapsed_time_ * freq);
            float v2 = 8.0f * std::cos(elapsed_time_ * freq * 0.5f);
            plot_view_.add_point(elapsed_time_, v1, v2);
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        control_view_.render();
        plot_view_.render();

        ImGui::Render();
        int w, h;
        glfwGetFramebufferSize(window_, &w, &h);
        glViewport(0, 0, w, h);
        glClearColor(0.12f, 0.12f, 0.14f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window_);
    }
}

} // namespace eot::ui

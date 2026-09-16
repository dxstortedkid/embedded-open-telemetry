#pragma once
#include <GLFW/glfw3.h>
#include "eot/ui/plot_view.hpp"
#include "eot/ui/control_view.hpp"

namespace eot::ui {

class App {
public:
    App();
    ~App();

    bool init(int width = 1280, int height = 720, const char* title = "Embedded Open Telemetry");
    void run();

private:
    GLFWwindow* window_ = nullptr;
    PlotView plot_view_;
    ControlView control_view_;
    float elapsed_time_ = 0.0f;
};

} // namespace eot::ui

#pragma once
#include "common/shared_context.hpp"

struct GLFWwindow;

class UIRenderer {
public:
    bool init(int width, int height, const char* title);
    void run_event_loop(SharedContext& ctx);
    void shutdown();
private:
    GLFWwindow* window_ = nullptr;
};
#pragma once
#include <vector>
#include "imgui.h"

namespace eot::ui {

class PlotView {
public:
    PlotView(int capacity = 2000);
    void add_point(float time, float val1, float val2);
    void clear();
    void render();

private:
    int capacity_;
    int offset_ = 0;
    float last_time_ = 0.0f;
    std::vector<ImVec2> channel_a_;
    std::vector<ImVec2> channel_b_;
    float history_window_ = 10.0f;
};

} // namespace eot::ui

#include "eot/ui/plot_view.hpp"
#include "implot.h"

namespace eot::ui {

PlotView::PlotView(int capacity) : capacity_(capacity) {
    channel_a_.reserve(capacity);
    channel_b_.reserve(capacity);
}

void PlotView::add_point(float time, float val1, float val2) {
    last_time_ = time;
    if (channel_a_.size() < static_cast<size_t>(capacity_)) {
        channel_a_.emplace_back(time, val1);
        channel_b_.emplace_back(time, val2);
    } else {
        channel_a_[offset_] = ImVec2(time, val1);
        channel_b_[offset_] = ImVec2(time, val2);
        offset_ = (offset_ + 1) % capacity_;
    }
}

void PlotView::clear() {
    channel_a_.clear();
    channel_b_.clear();
    offset_ = 0;
}

void PlotView::render() {
    ImGui::Begin("Waveform Monitor");

    ImGui::SliderFloat("Window (s)", &history_window_, 2.0f, 30.0f, "%.1f");
    ImGui::SameLine();
    if (ImGui::Button("Clear Waveforms")) clear();

    if (!channel_a_.empty() && ImPlot::BeginPlot("Telemetry Channels", ImVec2(-1, -1))) {
        ImPlot::SetupAxes("Timestamp (s)", "Amplitude");
        ImPlot::SetupAxisLimits(ImAxis_X1, last_time_ - history_window_, last_time_, ImGuiCond_Always);
        ImPlot::SetupAxisLimits(ImAxis_Y1, -15.0, 15.0);

        ImPlot::PlotLine("Channel 1 (Pitch)", &channel_a_[0].x, &channel_a_[0].y, 
                         static_cast<int>(channel_a_.size()), 0, offset_, sizeof(ImVec2));
        ImPlot::PlotLine("Channel 2 (Roll)", &channel_b_[0].x, &channel_b_[0].y, 
                         static_cast<int>(channel_b_.size()), 0, offset_, sizeof(ImVec2));

        ImPlot::EndPlot();
    }

    ImGui::End();
}

} // namespace eot::ui

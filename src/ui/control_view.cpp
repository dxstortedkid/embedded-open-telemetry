#include "eot/ui/control_view.hpp"
#include "imgui.h"

namespace eot::ui {

void ControlView::render() {
    ImGui::Begin("Device Control & Link");

    ImGui::TextColored(ImVec4(0.2f, 0.9f, 0.2f, 1.0f), "Status: Mock Stream Active");
    ImGui::Separator();

    const char* baud_rates[] = {"9600", "38400", "57600", "115200", "921600"};
    ImGui::Combo("Baud Rate", &baud_rate_idx_, baud_rates, IM_ARRAYSIZE(baud_rates));

    ImGui::SliderFloat("Sim Frequency (Hz)", &frequency_, 0.1f, 10.0f, "%.1f");

    if (streaming_) {
        if (ImGui::Button("Pause Stream", ImVec2(120, 0))) streaming_ = false;
    } else {
        if (ImGui::Button("Resume Stream", ImVec2(120, 0))) streaming_ = true;
    }

    ImGui::End();
}

} // namespace eot::ui

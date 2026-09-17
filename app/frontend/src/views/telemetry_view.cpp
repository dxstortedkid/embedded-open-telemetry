#include "frontend/views/telemetry_view.hpp"
#include <imgui.h>
#include <implot.h>

namespace Views {

void DrawViews(const TelemetrySnapshot& snapshot) {
    // 1. Окно Debug Info
    ImGui::SetNextWindowSize(ImVec2(300, 150), ImGuiCond_FirstUseEver);
    ImGui::Begin("Debug Info");
    ImGui::Text("GUI FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::Separator();
    ImGui::Text("Бэкенд тиков: %lu", snapshot.ticks);
    ImGui::Text("Текущее значение: %.4f", snapshot.current_val);
    ImGui::End();

    // 2. Окно Telemetry Plot
    ImGui::SetNextWindowSize(ImVec2(750, 450), ImGuiCond_FirstUseEver);
    ImGui::Begin("Telemetry Plot");
    // Флаги ImVec2(-1, -1) растягивают график на всё окно
    if (ImPlot::BeginPlot("Сигнал реального времени", ImVec2(-1, -1))) {
        ImPlot::SetupAxes("Время (с)", "Амплитуда", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);

        if (snapshot.count > 0) {
            // Новый API ImPlot (4 параметра)
            ImPlot::PlotLine(
                "Канал A",
                snapshot.time_data.data(),
                snapshot.val_data.data(),
                static_cast<int>(snapshot.count)
            );
        }
        ImPlot::EndPlot();
    }
    ImGui::End();
}

} // namespace Views
#include "common/shared_context.hpp"
#include "backend/engine.hpp"
#include "frontend/ui_renderer.hpp"
#include <thread>
#include <stop_token>

int main() {
    SharedContext context;
    BackendEngine engine;
    UIRenderer ui;

    if (!ui.init(1280, 720, "Embedded Open Telemetry (C++23)")) {
        return -1;
    }

    // Запускаем фоновый поток. В C++20/23 std::jthread автоматически
    // попросит поток остановиться и сделает join() при выходе из main.
    std::jthread backend_thread([&engine, &context](std::stop_token st) {
        engine.run(st, context);
    });

    // Блокирующий цикл отрисовки интерфейса (работает пока открыто окно)
    ui.run_event_loop(context);

    // Подчищаем OpenGL/GLFW перед выходом
    ui.shutdown();
    
    return 0;
}
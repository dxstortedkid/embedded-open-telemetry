#include "backend/engine.hpp"
#include <thread>
#include <chrono>
#include <cmath>
#include <algorithm> // Для std::shift_left

void BackendEngine::run(std::stop_token st, SharedContext& ctx) {
    float t = 0.0f;
    constexpr float dt = 0.016f; // шаг времени ~60 Гц

    while (!st.stop_requested()) {
        {
            std::lock_guard<std::mutex> lock(ctx.mtx);

            float val = std::sin(t * ctx.data.frequency);
            ctx.data.current_val = val;
            ctx.data.ticks++;

            // Заполнение кольцевого буфера
            if (ctx.data.count < BUFFER_SIZE) {
                ctx.data.time_data[ctx.data.count] = t;
                ctx.data.val_data[ctx.data.count] = val;
                ctx.data.count++;
            } else {
                // Буфер полон — сдвигаем влево и пишем в конец
                std::shift_left(ctx.data.time_data.begin(), ctx.data.time_data.end(), 1);
                std::shift_left(ctx.data.val_data.begin(), ctx.data.val_data.end(), 1);
                ctx.data.time_data[BUFFER_SIZE - 1] = t;
                ctx.data.val_data[BUFFER_SIZE - 1] = val;
            }
        }

        t += dt;
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
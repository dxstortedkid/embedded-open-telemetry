#pragma once
#include <mutex>
#include <array>
#include <cstddef>
#include <cstdint>

constexpr size_t BUFFER_SIZE = 500;

struct TelemetrySnapshot {
    std::array<float, BUFFER_SIZE> time_data{};
    std::array<float, BUFFER_SIZE> val_data{};
    size_t count = 0;

    uint64_t ticks = 0;
    float current_val = 0.0f;
    float frequency = 2.0f;
};

struct SharedContext {
    std::mutex mtx;
    TelemetrySnapshot data;

    // Быстрое и потокобезопасное копирование данных для рендера кадра
    TelemetrySnapshot get_snapshot() {
        std::lock_guard<std::mutex> lock(mtx);
        return data;
    }
};
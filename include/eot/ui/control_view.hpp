#pragma once

namespace eot::ui {

class ControlView {
public:
    void render();

    bool is_streaming() const { return streaming_; }
    float get_frequency() const { return frequency_; }

private:
    bool streaming_ = true;
    float frequency_ = 2.0f;
    int baud_rate_idx_ = 3;
};

} // namespace eot::ui

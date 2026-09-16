#include "eot/ui/app.hpp"

int main() {
    eot::ui::App app;
    if (!app.init(1280, 720, "Embedded Open Telemetry (EOT)")) {
        return -1;
    }
    app.run();
    return 0;
}

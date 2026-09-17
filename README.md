# Embedded Open Telemetry (EOT)

A lightweight, multithreaded C++23 application for real-time telemetry visualization. The project uses a strictly decoupled architecture, separating the computational backend from the frontend UI to ensure high performance, modularity, and thread safety.

## Architecture
The application operates using two primary threads:
* **UI Thread (Frontend):** Handles GLFW window events, OpenGL3 rendering, and Dear ImGui / ImPlot components. Locked to the monitor's refresh rate (V-Sync).
* **Worker Thread (Backend):** Executes data generation, processing, and hardware polling (`std::jthread`). 

Data synchronization between threads is securely managed via a mutex-protected `SharedContext`.

## Directory Structure
```text
.
├── app/
│   ├── backend/       # Background calculations and logic
│   ├── common/        # Thread-safe shared data structures (Contracts)
│   ├── frontend/      # ImGui windows, views, and rendering orchestrator
│   ├── third_party/   # Static dependencies (Dear ImGui, ImPlot)
│   ├── CMakeLists.txt # App module configuration
│   └── main.cpp       # Entry point and thread initialization
├── build/             # Build artifacts and final executable
├── CMakeLists.txt     # Root CMake configuration
└── README.md
```

## Dependencies
Ensure you have a C++23 compatible compiler, CMake, and the required system libraries.

**Arch Linux / CachyOS:**
```bash
sudo pacman -S base-devel cmake ninja git glfw mesa
```

## Build & Run
The project is configured using Modern CMake and the Ninja build system.

1. Configure the project:
```bash
cmake -B build -G Ninja
```

2. Compile the source code:
```bash
cmake --build build
```

3. Execute the application:
```bash
./build/eot_app
```
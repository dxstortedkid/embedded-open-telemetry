# OpenTelemetry / MCU Telemetry Studio (WIP)

A lightweight, hardware-accelerated desktop workstation designed for high-rate data visualization, real-time logging, and interactive debugging of microcontrollers (ESP32, STM32, RP2040, etc.).

## Core Purpose

Standard serial monitors are typically limited to raw text terminals or basic single-line plotters that struggle with high-bandwidth telemetry. This project bridges the gap by providing:
* **Multi-channel Realtime Streaming:** Native 60+ FPS plotting via Dear ImGui & ImPlot capable of handling hundreds of thousands of data points without dropping frames.
* **Universal Transport Layer:** Unified I/O interface supporting USB-Serial (CDC/UART), Bluetooth (BLE & Classic RFCOMM), and Wi-Fi (UDP / TCP / WebSockets).
* **Modular Pipeline Architecture:** Pluggable decoder architecture separating physical transport, frame parsing, and UI widgets.
* **Bidirectional Control:** Real-time parameter tuning (PID gains, filter cutoffs, setpoints) sent back to the MCU on the fly.

## Planned Architecture

Microcontroller → Transport Layer → Stream Framer → Protocol Decoders → Ring Buffers & DSP → ImPlot / Dataflow Graph

Transport: UART, BLE, Wi-Fi
Framing: COBS, SLIP, Line Delimiter
Protocols: Binary, Protobuf, CSV, CBOR
DSP: Filtering, FFT, Transformations
Output: Real-time Waveforms, Dashboards, Node-based Pipelines

## Target Platforms

* **Linux:** Arch / CachyOS, Fedora, Ubuntu (Wayland & X11 via OpenGL 3.3+ / Vulkan)
* **Windows:** Windows 10 / 11 (x64)
* **macOS:** Apple Silicon & Intel (Metal / OpenGL)

## Roadmap

- [x] Initial Dear ImGui + ImPlot runtime scaffold.
- [ ] Cross-platform serial port backend (libserialport / boost.asio).
- [ ] Transport abstraction interface (`ITransport`).
- [ ] Ring buffer memory engine for zero-allocation packet pushing.
- [ ] Protocol plugin API (C-ABI / dynamic shared libraries or compile-time registration).
- [ ] UDP / TCP network streams for Wi-Fi telemetry.
- [ ] Interactive Node-based data processing graph.
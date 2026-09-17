cmake_minimum_required(VERSION 3.20)
project(EmbeddedOpenTelemetry LANGUAGES CXX)

# Самый новый стабильный стандарт
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Генерирует compile_commands.json, чтобы линтер понял C++23 и пути к заголовкам
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Исполняемый файл появится прямо в build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Системные пакеты CachyOS
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(Threads REQUIRED) # Критически важно для std::jthread и stop_token

add_subdirectory(app)
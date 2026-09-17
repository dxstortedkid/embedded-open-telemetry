add_library(app_backend STATIC src/engine.cpp)
target_include_directories(app_backend PUBLIC include)
target_link_libraries(app_backend PUBLIC app_common)
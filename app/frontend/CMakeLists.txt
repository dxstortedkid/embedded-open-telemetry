add_library(app_frontend STATIC
    src/ui_renderer.cpp
    src/views/telemetry_view.cpp
)
target_include_directories(app_frontend PUBLIC include)
target_link_libraries(app_frontend PUBLIC 
    app_common 
    imgui 
    implot
)
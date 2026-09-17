# --- Dear ImGui ---
add_library(imgui STATIC
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC 
    imgui 
    imgui/backends
)
target_link_libraries(imgui PUBLIC 
    glfw 
    OpenGL::GL
)

# --- ImPlot ---
add_library(implot STATIC
    implot/implot.cpp
    implot/implot_items.cpp
)
target_include_directories(implot PUBLIC 
    implot
)
target_link_libraries(implot PUBLIC 
    imgui
)
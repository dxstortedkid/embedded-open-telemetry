add_subdirectory(third_party)
add_subdirectory(common)
add_subdirectory(backend)
add_subdirectory(frontend)

add_executable(eot_app main.cpp)

target_link_libraries(eot_app PRIVATE 
    app_backend 
    app_frontend
    Threads::Threads  # Добавили линковку потоков ОС
)
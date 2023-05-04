project(Editor)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME}      PUBLIC imgui PRIVATE Platform Components Assets Math Graphics Physics)

target_precompile_headers(${PROJECT_NAME} PRIVATE stl.hpp)
target_sources(${PROJECT_NAME}            PRIVATE editor.cpp light_window.cpp material_window.cpp physics_debug.cpp
                                                  texture_window.cpp camera_window.cpp)
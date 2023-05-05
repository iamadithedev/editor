project(Editor)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)

target_precompile_headers(${PROJECT_NAME}  PRIVATE stl.hpp)
target_link_libraries(${PROJECT_NAME}      PRIVATE Platform Components Assets Math Graphics Physics imgui)

target_sources(${PROJECT_NAME}  PRIVATE editor.cpp physics_debug.cpp)
target_sources(${PROJECT_NAME}  PRIVATE Components/light_window.cpp Components/camera_window.cpp)
target_sources(${PROJECT_NAME}  PRIVATE Assets/material_window.cpp Assets/texture_window.cpp)
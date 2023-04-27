#pragma once

#include "editor_window.hpp"
#include "Base/window.hpp"

class Editor
{
public:
    void init(base::Window* window);
    void release();
    void draw();

    void begin(int32_t width, int32_t height, float total_time);
    void end();

    void add_window(EditorWindow* window);

private:
    std::vector<EditorWindow*> _windows;
};
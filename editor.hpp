#pragma once

#include "buffer.hpp"
#include "physics.hpp"
#include "program.hpp"
#include "vertex_array.hpp"
#include "physics_debug.hpp"
#include "editor_window.hpp"

#include "Base/window.hpp"

class Editor
{
public:
    Editor();

    void init(base::Window* window, Physics* physics);
    void release();

    void draw(Buffer* matrices_buffer);

    void begin(int32_t width, int32_t height, float total_time);
    void end();

    void add_window(EditorWindow* window);

private:
    std::vector<EditorWindow*> _windows;

    PhysicsDebug _debug;
    VertexArray  _debug_vertex_array;

    Buffer  _debug_vertex_buffer;
    Buffer  _debug_indices_buffer;
    Program _debug_program;
};
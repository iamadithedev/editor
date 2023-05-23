#pragma once

#include "buffer.hpp"
#include "shader.hpp"
#include "physics_world.hpp"
#include "vertex_array.hpp"
#include "physics_debug.hpp"
#include "editor_window.hpp"
#include "resource_manager.hpp"

#include "base/window.hpp"

class Editor
{
public:
    Editor();

    void init(base::Window* window, ResourceManager* resources, PhysicsWorld* physics);
    void release();

    void draw(const Buffer* matrices_ubo);

    void begin(int32_t width, int32_t height, float total_time);
    void end();

    void add_window(EditorWindow* window);

private:
    std::vector<EditorWindow*> _windows;

    PhysicsDebug _debug;
    VertexArray  _debug_vao;

    Shader* _debug_shader;
    Buffer  _debug_vbo;
    Buffer  _debug_ibo;
};
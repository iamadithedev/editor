#include "editor.hpp"
#include "file.hpp"

#include "GLFW/window.hpp"
//#define   DEBUG

Editor::Editor()
    : _debug_vbo { GL_ARRAY_BUFFER, GL_STATIC_DRAW }
    , _debug_ibo { GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW }
{
}

void Editor::init(base::Window* window, PhysicsWorld* physics)
{
    assert(window != nullptr);

    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(((glfw::Window*)window)->handle(), true);
    ImGui_ImplOpenGL3_Init();

    physics->add_debug(&_debug);

    // ==================================================================================

    auto debug_vertex_source   = File::read<char>("../Assets/glsl/debug.vert.glsl");
    auto debug_fragment_source = File::read<char>("../Assets/glsl/debug.frag.glsl");

    ShaderStage debug_vertex_shader { "debug.vert.glsl", GL_VERTEX_SHADER };
    debug_vertex_shader.create();
    debug_vertex_shader.source(debug_vertex_source);

    ShaderStage debug_fragment_shader { "debug.frag.glsl", GL_FRAGMENT_SHADER };
    debug_fragment_shader.create();
    debug_fragment_shader.source(debug_fragment_source);

    _debug_shader.create();
    _debug_shader.attach(&debug_vertex_shader);
    _debug_shader.attach(&debug_fragment_shader);
    _debug_shader.link();

    _debug_shader.detach(&debug_vertex_shader);
    _debug_shader.detach(&debug_fragment_shader);

    debug_vertex_shader.destroy();
    debug_fragment_shader.destroy();

    // ==================================================================================

    vertex_attributes debug_vertex_attributes =
    {
        { 0, 3, GL_FLOAT, (int32_t)offsetof(mesh_vertex::debug, position) },
        { 1, 3, GL_FLOAT, (int32_t)offsetof(mesh_vertex::debug, color) }
    };

    _debug_vao.create();
    _debug_vao.bind();

    _debug_vbo.create();
    _debug_vbo.bind();

    _debug_ibo.create();
    _debug_ibo.bind();

    _debug_vao.init_attributes_of_type<mesh_vertex::debug>(debug_vertex_attributes);
}

void Editor::release()
{
}

void Editor::draw(Buffer* matrices_ubo)
{
    #ifdef DEBUG

    const auto& geometry = _debug.geometry();
    auto  debug_submesh  = geometry.get_submesh();

    glm::mat4 model { 1.0f };
    matrices_ubo->sub_data(BufferData::make_data(&model));

    _debug_shader.bind();
    _debug_vao.bind();

    _debug_vbo.data(BufferData::make_data(geometry.vertices()));
    _debug_ibo.data(BufferData::make_data(geometry.faces()));

    glDrawElements(GL_LINES, debug_submesh.count, GL_UNSIGNED_INT, reinterpret_cast<std::byte*>(debug_submesh.index));

    #endif

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Editor::begin(int32_t width, int32_t height, float total_time)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame(width, height, total_time);

    ImGui::NewFrame();
}

void Editor::end()
{
    for (auto window : _windows)
    {
        window->draw();
    }

    ImGui::Render();
}

void Editor::add_window(EditorWindow* window)
{
    _windows.push_back(window);
}

#include "editor.hpp"
#include "file.hpp"

#include "GLFW/window.hpp"
//#define   DEBUG

Editor::Editor()
    : _debug_vertex_buffer  { GL_ARRAY_BUFFER,         GL_STATIC_DRAW }
    , _debug_indices_buffer { GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW }
{
}

void Editor::init(base::Window* window, Physics* physics)
{
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(((glfw::Window*)window)->handle(), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    //ImGuiIO& io = ImGui::GetIO();

    physics->add_debug(&_debug);

    // ==================================================================================

    auto debug_vertex_source   = File::read("../debug_vert.glsl");
    auto debug_fragment_source = File::read("../debug_frag.glsl");

    Shader debug_vertex_shader {"debug_vert.glsl", GL_VERTEX_SHADER };
    debug_vertex_shader.create();
    debug_vertex_shader.source(debug_vertex_source.data());

    Shader debug_fragment_shader {"debug_frag.glsl", GL_FRAGMENT_SHADER };
    debug_fragment_shader.create();
    debug_fragment_shader.source(debug_fragment_source.data());

    _debug_program.create();
    _debug_program.attach(&debug_vertex_shader);
    _debug_program.attach(&debug_fragment_shader);
    _debug_program.link();

    _debug_program.detach(&debug_vertex_shader);
    _debug_program.detach(&debug_fragment_shader);

    debug_vertex_shader.destroy();
    debug_fragment_shader.destroy();

    // ==================================================================================

    vertex_attributes debug_vertex_attributes =
    {
        { 0, 3, (int32_t)offsetof(mesh_vertex::debug, position) },
        { 1, 3, (int32_t)offsetof(mesh_vertex::debug, color) }
    };

    _debug_vertex_array.create();
    _debug_vertex_array.bind();

    _debug_vertex_buffer.create();
    _debug_vertex_buffer.bind();

    _debug_indices_buffer.create();
    _debug_indices_buffer.bind();

    _debug_vertex_array.init_attributes_of_type<mesh_vertex::debug>(debug_vertex_attributes);
}

void Editor::release()
{
}

void Editor::draw(Buffer* matrices_buffer)
{
    #ifdef DEBUG

    const auto& geometry = _debug.geometry();

    glm::mat4 model { 1.0f };
    matrices_buffer->sub_data(BufferData::make_data(&model));

    _debug_program.bind();
    _debug_vertex_array.bind();

    _debug_vertex_buffer.data(BufferData::make_data(geometry.vertices()));
    _debug_indices_buffer.data(BufferData::make_data(geometry.faces()));

    glDrawElements(GL_LINES, (int32_t)geometry.faces().size() * 2, GL_UNSIGNED_INT, 0);

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

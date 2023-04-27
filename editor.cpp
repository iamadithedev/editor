#include "editor.hpp"

#include "GLFW/window.hpp"

void Editor::init(base::Window* window)
{
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(((glfw::Window*)window)->handle(), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    //ImGuiIO& io = ImGui::GetIO();
}

void Editor::release()
{
}

void Editor::draw()
{
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
    for (auto _window : _windows)
    {
        _window->draw();
    }

    ImGui::Render();
}

void Editor::add_window(EditorWindow* window)
{
    _windows.push_back(window);
}

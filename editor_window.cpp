#include "editor_window.hpp"

EditorWindow::EditorWindow(std::string title)
    : _title { std::move(title) }
{
}

void EditorWindow::draw()
{
    ImGui::Begin(_title.c_str());

    draw_layout();

    ImGui::End();
}

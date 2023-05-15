#include "render_pass_window.hpp"

RenderPassWindow::RenderPassWindow()
    : EditorWindow { "RenderPass" }
{
}

void RenderPassWindow::draw_layout()
{
    ImGuiIO& io = ImGui::GetIO();

    if (ImGui::ColorEdit3("Clear color", (float*) &_clear_color, ImGuiColorEditFlags_NoOptions))
    {
        _render_pass->clear_color(_clear_color);
    }

    ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
}

void RenderPassWindow::set_render_pass(RenderPass* render_pass, const rgb& color)
{
    _render_pass = render_pass;
    _clear_color = color;
}

#include "render_pass_window.hpp"

void RenderPassWindow::draw()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Begin("RenderPass");

    if (ImGui::ColorEdit3("Clear color", (float*) &_clear_color, ImGuiColorEditFlags_NoOptions))
    {
        _render_pass->clear_color(_clear_color.r, _clear_color.g, _clear_color.b);
    }

    ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

    ImGui::End();
}

void RenderPassWindow::set_render_pass(RenderPass* render_pass, const rgb& color)
{
    _render_pass = render_pass;
    _clear_color = color;
}

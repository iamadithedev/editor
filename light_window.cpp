#include "light_window.hpp"

void LightWindow::draw()
{
    ImGui::Begin("Light");

    if (ImGui::InputFloat3("Position", (float*)&_position))
    {
        _light->position(_position);
    }

    if (ImGui::ColorEdit3("Color", (float*)&_color, ImGuiColorEditFlags_NoOptions))
    {
        _light->color(_color);
    }

    ImGui::End();
}

void LightWindow::set_light(Light* light)
{
    _light    = light;
    _position = light->position();
    _color    = light->color();
}

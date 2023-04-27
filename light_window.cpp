#include "light_window.hpp"

void LightWindow::draw()
{
    ImGui::Begin("Light");
    ImGui::ColorEdit3("Color", (float*)&_color, ImGuiColorEditFlags_NoOptions);
    ImGui::End();

    _light->color(_color);
}

void LightWindow::set_light(Light* light)
{
    _light = light;
    _color = light->color();
}

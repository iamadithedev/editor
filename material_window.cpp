#include "material_window.hpp"

void MaterialWindow::draw()
{
    ImGui::Begin("Material");

    if (ImGui::ColorEdit3("Diffuse", (float*) &_diffuse, ImGuiColorEditFlags_NoOptions))
    {
        _material->diffuse(_diffuse);
    }

    ImGui::End();
}

void MaterialWindow::set_material(Material* material)
{
    _material = material;
    _diffuse  = material->diffuse();
}

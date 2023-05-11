#include "material_window.hpp"

MaterialWindow::MaterialWindow()
    : EditorWindow { "Material" }
{
}

void MaterialWindow::draw_layout()
{
    if (ImGui::ColorEdit3("Diffuse", (float*) &_diffuse, ImGuiColorEditFlags_NoOptions))
    {
        _material->diffuse(_diffuse);
    }
}

void MaterialWindow::set_material(Material* material)
{
    _material = material;
    _diffuse  = material->diffuse();
}

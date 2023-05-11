#pragma once

#include "editor_window.hpp"
#include "material.hpp"

class MaterialWindow final : public EditorWindow
{
public:
    MaterialWindow();

    void draw_layout() final;

    void set_material(Material* material);

private:
    Material* _material;
    rgb       _diffuse;
};
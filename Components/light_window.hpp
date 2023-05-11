#pragma once

#include "editor_window.hpp"
#include "light.hpp"

class LightWindow final : public EditorWindow
{
public:
    LightWindow();

    void draw_layout() final;

    void set_light(Light* light);

private:
    Light* _light;

    vec3   _position;
    rgb    _color;
};

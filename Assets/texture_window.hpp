#pragma once

#include "editor_window.hpp"
#include "texture.hpp"
#include "vec2.hpp"

class TextureWindow final : public EditorWindow
{
public:
    TextureWindow();

    void draw_layout() final;

    void set_texture(Texture* texture, const TextureData& data);

private:
    Texture* _texture;

    int32_t  _width;
    int32_t  _height;
};
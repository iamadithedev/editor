#include "texture_window.hpp"

TextureWindow::TextureWindow()
    : EditorWindow { "Texture" }
{
}

void TextureWindow::draw_layout()
{
    ImGui::Image((void*)(intptr_t)_texture->handle(), { 256, 256 }); // TODO fix flipped image
    ImGui::Text("Width %.1i - Height %.1i", _width, _height);
}

void TextureWindow::set_texture(Texture* texture, const TextureData& data)
{
    _texture = texture;
    _width   = data.width();
    _height  = data.height();
}

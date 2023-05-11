#pragma once

#include "editor_window.hpp"
#include "render_pass.hpp"
#include "rgb.hpp"

class RenderPassWindow final : public EditorWindow
{
public:
    RenderPassWindow();

    void draw_layout() final;

    void set_render_pass(RenderPass* render_pass, const rgb& color);

private:
    RenderPass* _render_pass;

    rgb _clear_color;
};
#pragma once

#include "editor_window.hpp"
#include "camera.hpp"

class CameraWindow final : public EditorWindow
{
public:
    void draw() final;

    void set_camera(Camera* camera, float fov);

private:
    Camera* _camera;
    float   _fov;
};
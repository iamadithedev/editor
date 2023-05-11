#pragma once

#include "editor_window.hpp"
#include "transform.hpp"
#include "camera.hpp"

class CameraWindow final : public EditorWindow
{
public:
    CameraWindow();

    void draw_layout() final;

    void set_camera(Camera* camera);
    void set_transform(Transform* transform, const vec3& position);

private:
    Transform* _transform;
    Camera*    _camera;

    vec3  _position;
    float _fov;
};
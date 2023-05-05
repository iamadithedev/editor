#include "camera_window.hpp"

void CameraWindow::draw()
{
    ImGui::Begin("Camera");

    if (ImGui::InputFloat3("Position", (float*)&_position))
    {
        _transform->translate(_position);
    }

    if (ImGui::SliderFloat("Fov", &_fov, 45.0f, 120.0f))
    {
        _camera->field_of_view(_fov);
    }

    ImGui::End();
}

void CameraWindow::set_camera(Camera* camera)
{
    _camera = camera;
    _fov    = camera->field_of_view();
}

void CameraWindow::set_transform(Transform* transform, const vec3& position)
{
    _transform = transform;
    _position  = position;
}

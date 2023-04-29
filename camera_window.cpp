#include "camera_window.hpp"

void CameraWindow::draw()
{
    ImGui::Begin("Camera");
    ImGui::SliderFloat("Fov", &_fov, 45, 120);
    ImGui::End();
}

void CameraWindow::set_camera(Camera* camera, float fov)
{
    _camera = camera;
    _fov    = fov;
}

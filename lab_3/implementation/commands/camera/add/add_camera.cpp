#include <implementation/managers/singleton.hpp>
#include <implementation/objects/model/model_details/point/point.hpp>
#include <implementation/objects/camera/camera.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "add_camera.hpp"

AddCamera::AddCamera(double x_pos, double y_pos, double z_pos) : x_pos(x_pos), y_pos(y_pos), z_pos(z_pos) {}

void AddCamera::execute() {
    Point cam_pos(x_pos, y_pos, z_pos);

    auto camera = std::make_shared<Camera>();
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();
    auto scene = scene_manager.getScene();

    camera->transform(cam_pos, cam_pos, cam_pos);
    scene->addObject(camera);
    scene_manager.setMainCamera(scene->end() - 1);
}

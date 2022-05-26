#include <implementation/managers/manager_creator.hpp>
#include <implementation/objects/model/wireframe_model/model_details/point/point.hpp>
#include <implementation/objects/camera/camera.hpp>
#include "add_camera.hpp"

AddCamera::AddCamera(double x_pos, double y_pos, double z_pos) {
    this->camera = std::make_shared<Camera>(Point(x_pos, y_pos, z_pos));
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::addObject;
}

AddCamera::AddCamera(std::shared_ptr<Object> camera) : camera(camera) {
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::addObject;
}

void AddCamera::execute() {
    ((*manager).*method)(camera);
}


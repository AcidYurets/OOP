#include <implementation/managers/manager_creator.hpp>
#include <utility>
#include "get_main_camera.hpp"

GetMainCamera::GetMainCamera(std::shared_ptr<Camera> &camera) : camera(camera) {
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getMainCamera;
}

void GetMainCamera::execute() {
    this->camera = ((*manager).*method)();
}
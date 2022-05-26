#include <implementation/managers/manager_creator.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/facade/facade.hpp>
#include "set_camera.hpp"

SetCamera::SetCamera(size_t camera_id) : camera_id(camera_id) {}

void SetCamera::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::setMainCamera;
}

void SetCamera::execute() {
    ((*manager).*method)(camera_id);
}

 
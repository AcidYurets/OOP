#include <implementation/managers/manager_creator.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/facade/facade.hpp>
#include "remove_camera.hpp"

RemoveCamera::RemoveCamera(std::size_t camera_id) : camera_id(camera_id) {}

void RemoveCamera::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::removeObject;
}

void RemoveCamera::execute() {
    ((*manager).*method)(camera_id);
}


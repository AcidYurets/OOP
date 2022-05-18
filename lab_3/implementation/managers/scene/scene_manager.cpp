//

//

#include <implementation/exceptions/load_exceptions.hpp>
#include "implementation/objects/camera/camera.hpp"
#include "scene_manager.hpp"

SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}

std::shared_ptr<Camera> SceneManager::getMainCamera() const {
    auto camera_ptr = this->main_camera.lock();

    if (camera_ptr == nullptr) throw NoCameraError(__FILE__, __LINE__, "main camera doesn't installed");

    return camera_ptr;
}

std::shared_ptr<Scene> SceneManager::getScene() const {
    return this->scene;
}

void SceneManager::setScene(std::shared_ptr<Scene> new_scene) {
    this->scene = std::move(new_scene);
}

void SceneManager::setMainCamera(const Iterator &it) {
    this->main_camera = std::dynamic_pointer_cast<Camera>(*it);
}

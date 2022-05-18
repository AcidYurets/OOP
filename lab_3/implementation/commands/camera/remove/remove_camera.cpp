#include <implementation/managers/singleton.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "remove_camera.hpp"

RemoveCamera::RemoveCamera(std::size_t camera_id) : camera_id(camera_id) {}

void RemoveCamera::execute() {
    auto scene = Singleton<SceneManager>::instance().getScene();
    auto it = scene->begin();

    std::advance(it, camera_id);
    scene->removeObject(it);
}

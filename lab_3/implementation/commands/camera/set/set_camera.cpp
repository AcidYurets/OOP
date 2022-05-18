#include <implementation/managers/singleton.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "set_camera.hpp"

SetCamera::SetCamera(size_t camera_id) : camera_id(camera_id) {}

void SetCamera::execute() {
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();

    auto it = scene_manager.getScene()->begin();
    std::advance(it, camera_id);

    scene_manager.setMainCamera(it);
}

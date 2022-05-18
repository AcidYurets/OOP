#include <implementation/managers/singleton.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/managers/transform/transform_manager.hpp>
#include "move_camera.hpp"

MoveCamera::MoveCamera(std::size_t camera_id, double shift_x, double shift_y) : camera_id(camera_id), shift_x(shift_x),
                                                                                shift_y(shift_y) {}

void MoveCamera::execute() {
    Point shift(shift_x, shift_y, 0);

    decltype(auto) scene_manager = Singleton<SceneManager>::instance();
    decltype(auto) transform_manager = Singleton<TransformManager>::instance();

    auto it = scene_manager.getScene()->begin();
    std::advance(it, camera_id);

    transform_manager.transform(*it, shift, shift, shift);
}


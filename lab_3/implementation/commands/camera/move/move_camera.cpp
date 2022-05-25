#include <implementation/managers/manager_creator.hpp>
#include <implementation/objects/model/wireframe_model/model_details/point/point.hpp>
#include "move_camera.hpp"

MoveCamera::MoveCamera(std::shared_ptr<Object> camera, double shift_x, double shift_y){
    this->manager = ManagerCreator<TransformManager>().getManager();
    this->method = &TransformManager::transform;
}

void MoveCamera::execute() {
    ((*manager).*method)(camera, Point(shift_x, shift_y, 0), Point(shift_x, shift_y, 0), Point(shift_x, shift_y, 0));
}


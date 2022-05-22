#include <implementation/managers/manager_creator.hpp>
#include <implementation/objects/model/wireframe_model/model_details/point/point.hpp>
#include "rotate_model.hpp"


RotateModel::RotateModel(std::shared_ptr<Object> model, double ax, double ay, double az) 
                                                : model(model), ax(ax), ay(ay), az(az) {
    this->manager = ManagerCreator<TransformManager>().getManager();
    this->method = &TransformManager::transform;
}

void RotateModel::execute() {
    ((*manager).*method)(model, Point(0, 0, 0), Point(1, 1, 1), Point(ax, ay, az));
}

#include <implementation/managers/manager_creator.hpp>
#include <implementation/objects/model/wireframe_model/model_details/point/point.hpp>
#include "move_model.hpp"


MoveModel::MoveModel(std::shared_ptr<Object> model, double dx, double dy, double dz) 
                                            : model(model), dx(dx), dy(dy), dz(dz) {
    this->manager = ManagerCreator<TransformManager>().getManager();
    this->method = &TransformManager::transform;      
}

void MoveModel::execute() {
    ((*manager).*method)(model, Point(dx, dy, dz), Point(1, 1, 1), Point(0, 0, 0));
}

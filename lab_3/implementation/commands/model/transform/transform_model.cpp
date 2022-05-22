#include <implementation/managers/manager_creator.hpp>
#include <implementation/objects/model/wireframe_model/model_details/point/point.hpp>
#include "transform_model.hpp"


TransformModel::TransformModel(std::shared_ptr<Object> model, const Point &move, const Point &scale, const Point &rotate)
                                                    : model(model), move(move), scale(scale), rotate(rotate) {
    this->manager = ManagerCreator<TransformManager>().getManager();
    this->method = &TransformManager::transform;
}

void TransformModel::execute()
{
    ((*manager).*method)(model, move, scale, rotate);
}
#include <implementation/managers/manager_creator.hpp>
#include <implementation/objects/model/wireframe_model/model_details/point/point.hpp>
#include <implementation/facade/facade.hpp>
#include "scale_model.hpp"

ScaleModel::ScaleModel(std::shared_ptr<Object> model, const double kx, const double ky, const double kz) 
                    : model(model), kx(kx), ky(ky), kz(kz) {}

void ScaleModel::init(Facade &facade) {
    this->manager = facade.getTransformManager();
    this->method = &TransformManager::transform;
}

void ScaleModel::execute() {
    ((*manager).*method)(model, Point(0, 0, 0), Point(kx, ky, kz), Point(0, 0, 0));
}
 
#include <implementation/managers/singleton.hpp>
#include <implementation/objects/model/wireframe_model/model_details/point/point.hpp>
#include "scale_model.hpp"

ScaleModel::ScaleModel(WireframeModel model, const double kx, const double ky, const double kz) 
                    : model(model), kx(kx), ky(ky), kz(kz) {
    this->manager = Singleton<TransformManager>::instance();
    this->method = &TransformManager::transform;
}

void ScaleModel::execute() {
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();
    // decltype(auto) transform_manager = Singleton<TransformManager>::instance();

    // auto models_iter = scene_manager.getScene()->begin();
    // std::advance(models_iter, 2);
    // auto model = *models_iter;
//    std::shared_ptr<Object> model = scene_manager->getScene()->getObjects().at(model_id);
    //transform_manager.transform(model, Point(0, 0, 0), Point(kx, ky, kz), Point(0, 0, 0));
    ((*manager).*method)(model, Point(0, 0, 0), Point(kx, ky, kz), Point(0, 0, 0));
}

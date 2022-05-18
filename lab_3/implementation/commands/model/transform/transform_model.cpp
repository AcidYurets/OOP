#include <implementation/managers/singleton.hpp>
#include <implementation/objects/model/model_details/point/point.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/managers/transform/transform_manager.hpp>
#include "transform_model.hpp"


TransformModel::TransformModel(std::size_t model_id, const Point &move, const Point &scale, const Point &rotate)
    : model_id(model_id), move(move), scale(scale), rotate(rotate) {}

void TransformModel::execute()
{
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();
    decltype(auto) transform_manager = Singleton<TransformManager>::instance();

    auto models_iter = scene_manager.getScene()->begin();
    std::advance(models_iter, model_id);

    auto model = *models_iter;
//    std::shared_ptr<Object> model = scene_manager->getScene()->getObjects().at(model_id);
    transform_manager.transform(model, move, scale, rotate);
}
#include <implementation/managers/singleton.hpp>
#include <implementation/objects/model/model_details/point/point.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/managers/transform/transform_manager.hpp>
#include "rotate_model.hpp"


RotateModel::RotateModel(std::size_t model_id, double ax, double ay, double az) : model_id(model_id), ax(ax), ay(ay),
                                                                                  az(az) {}

void RotateModel::execute() {
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point rotate(ax, ay, az);

    decltype(auto) scene_manager = Singleton<SceneManager>::instance();
    decltype(auto) transform_manager = Singleton<TransformManager>::instance();

    auto models_iter = scene_manager.getScene()->begin();
    std::advance(models_iter, model_id);

    auto model = *models_iter;
//    std::shared_ptr<Object> model = scene_manager->getScene()->getObjects().at(model_id);
    transform_manager.transform(model, move, scale, rotate);
}

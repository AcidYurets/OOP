#include <memory>
#include <implementation/managers/singleton.hpp>
#include <implementation/objects/model/model_details/point/point.hpp>
#include <implementation/objects/object.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/managers/transform/transform_manager.hpp>
#include "move_model.hpp"


MoveModel::MoveModel(size_t model_id, double dx, double dy, double dz) : model_id(model_id), dx(dx), dy(dy), dz(dz) {}

void MoveModel::execute() {
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point rotate(0, 0, 0);

    decltype(auto) scene_manager = Singleton<SceneManager>::instance();
    decltype(auto) transform_manager = Singleton<TransformManager>::instance();

    auto models_iter = scene_manager.getScene()->begin();
    std::advance(models_iter, model_id);

    auto model = *models_iter;

//    std::shared_ptr<Object> model = scene_manager->getScene()->getObjects().at(model_id);
    transform_manager.transform(model, move, scale, rotate);
}

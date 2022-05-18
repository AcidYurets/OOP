#include <implementation/managers/singleton.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "remove_model.hpp"

RemoveModel::RemoveModel(size_t model_id) : model_id(model_id) {}

void RemoveModel::execute() {
    auto scene = Singleton<SceneManager>::instance().getScene();
    auto it = scene->begin();
    std::advance(it, model_id);
    scene->removeObject(it);
}
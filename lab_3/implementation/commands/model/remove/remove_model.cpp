#include <implementation/managers/manager_creator.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/facade/facade.hpp>
#include "remove_model.hpp"

RemoveModel::RemoveModel(size_t model_id) : model_id(model_id) {}

void RemoveModel::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::removeObject;
}

void RemoveModel::execute() {
    ((*manager).*method)(model_id);
}
#include <implementation/managers/manager_creator.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "add_model.hpp"

AddModel::AddModel(std::shared_ptr<Object> model) : model(model) {
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::addObject;
}

void AddModel::execute() {
    ((*manager).*method)(model);
}


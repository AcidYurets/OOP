#include <implementation/managers/singleton.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "add_model.hpp"

void AddModel::execute() {
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();

    scene_manager.getScene()->addObject(model);
}

AddModel::AddModel(std::shared_ptr<Object> model) : model(model) {}
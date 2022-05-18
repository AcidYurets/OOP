#include <implementation/managers/singleton.hpp>
#include <implementation/managers/load/load_manager.hpp>
#include <implementation/load/directors/model/model_director.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "load_model.hpp"


LoadModel::LoadModel(std::string filename) : filename(filename) {}

void LoadModel::execute() {
    decltype(auto) load_manager = Singleton<LoadManager>::instance();
    load_manager.setDirector(std::make_shared<ModelDirector>());

    auto model = load_manager.load(filename);
    Singleton<SceneManager>::instance().getScene()->addObject(model);
}
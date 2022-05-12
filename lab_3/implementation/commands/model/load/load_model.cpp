//
// Created by ivaaahn on 23.05.2021.
//

#include <implementation/managers/load/load_manager.hpp>
#include <implementation/load/directors/model/model_director.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "load_model.hpp"


LoadModel::LoadModel(std::string filename) : filename(filename) {}

void LoadModel::execute() {
    auto load_manager = LoadManagerCreator().getManager();
    load_manager->setDirector(std::make_shared<ModelDirector>());

    auto model = load_manager->load(filename);
    SceneManagerCreator().getManager()->getScene()->addObject(model);
}
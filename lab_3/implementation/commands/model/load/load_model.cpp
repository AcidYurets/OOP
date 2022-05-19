#include <implementation/managers/singleton.hpp>
#include <implementation/managers/load/load_manager.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/load/directors/model/wireframe_model/wireframe_model_director.hpp>
#include <implementation/load/builders/model/file_model_builder/file_wireframe_model_builder/file_wireframe_model_builder.hpp>
#include "load_model.hpp"

LoadModel::LoadModel(std::string filename) : filename(filename) {}

void LoadModel::execute() {
    decltype(auto) load_manager = Singleton<LoadManager>::instance();
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();

    decltype(auto) builder = std::make_shared<FileWireframeModelBuilder>();
    decltype(auto) director = std::make_shared<WireframeModelDirector>(builder);
    load_manager.setDirector(director);

    decltype(auto) model = load_manager.load(filename);
    scene_manager.getScene()->addObject(model);
}
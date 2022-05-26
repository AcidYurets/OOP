#include <implementation/managers/manager_creator.hpp>
#include <implementation/facade/facade.hpp>
#include <utility>
#include "get_scene.hpp"

GetScene::GetScene(std::shared_ptr<Scene> &scene) : scene(scene) {}

void GetScene::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::getScene;
}

void GetScene::execute() {
    this->scene = ((*manager).*method)();
}
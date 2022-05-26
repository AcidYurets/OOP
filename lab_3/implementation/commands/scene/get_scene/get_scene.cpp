#include <implementation/managers/manager_creator.hpp>
#include <utility>
#include "get_scene.hpp"

GetScene::GetScene(std::shared_ptr<Scene> &scene) : scene(scene) {
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getScene;
}

void GetScene::execute() {
    this->scene = ((*manager).*method)();
}
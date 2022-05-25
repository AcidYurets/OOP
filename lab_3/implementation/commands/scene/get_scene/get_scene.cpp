#include <implementation/managers/manager_creator.hpp>
#include <utility>
#include "get_scene.hpp"

GetScene::GetScene(){
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getScene;
}

void GetScene::execute() {
    ((*manager).*method)();
}
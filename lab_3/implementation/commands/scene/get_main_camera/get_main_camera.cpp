#include <implementation/managers/manager_creator.hpp>
#include <utility>
#include "get_main_camera.hpp"

GetMainCamera::GetMainCamera(){
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getMainCamera;
}

void GetMainCamera::execute() {
    ((*manager).*method)();
}
#include <implementation/managers/manager_creator.hpp>
#include "count_cameras.hpp"

CountCameras::CountCameras(std::shared_ptr<size_t> &count) : count(count) {
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getCamerasCount;
}

void CountCameras::execute() {
    *(this->count) = ((*manager).*method)();
}

 
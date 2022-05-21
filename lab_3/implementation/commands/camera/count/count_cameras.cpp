#include <implementation/managers/singleton.hpp>
#include "count_cameras.hpp"

CountCameras::CountCameras(std::shared_ptr<size_t> &count) : count(count) {
    this->manager = Singleton<SceneManager>::instance();
    this->method = &SceneManager::getCamerasCount;
}

void CountCameras::execute() {
    *(this->count) = ((*manager).*method)();
}


#include <implementation/managers/singleton.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "count_cameras.hpp"

CountCameras::CountCameras(std::shared_ptr<size_t> &count) : count(count) {}

void CountCameras::execute() {
    *(this->count) = Singleton<SceneManager>::instance().getScene()->getCamerasCount();
}


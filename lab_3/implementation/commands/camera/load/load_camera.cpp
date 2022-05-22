#include <implementation/managers/manager_creator.hpp>
#include "load_camera.hpp"

LoadCamera::LoadCamera(std::shared_ptr<Object> &camera, std::string filename) : filename(filename), camera(camera) {
    this->manager = ManagerCreator<LoadManager>().getManager();
    this->method = &LoadManager::load;
}

void LoadCamera::execute() {
    camera = ((*manager).*method)(filename, 1);
}

#include "facade.hpp"

Facade::Facade() {
    this->loadManager = ManagerCreator<LoadManager>().getManager();
    this->drawManager = ManagerCreator<DrawManager>().getManager();
    this->transformManager = ManagerCreator<TransformManager>().getManager();
    this->sceneManager = ManagerCreator<SceneManager>().getManager();
}

std::shared_ptr<LoadManager> Facade::getLoadManager() {
    return loadManager;
}

void Facade::execute(const std::shared_ptr<Command> &command) {
    command->init(*this);
    command->execute();
}

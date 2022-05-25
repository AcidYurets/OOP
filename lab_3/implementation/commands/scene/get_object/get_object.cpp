#include <implementation/managers/manager_creator.hpp>
#include <utility>
#include "get_object.hpp"

GetObject::GetObject(size_t id) : id(id) {
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getObjectById;
}

void GetObject::execute() {
    ((*manager).*method)(id);
}
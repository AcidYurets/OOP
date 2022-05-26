#include <implementation/managers/manager_creator.hpp>
#include <utility>
#include "get_object.hpp"

GetSceneObject::GetSceneObject(std::shared_ptr<Object> &object, size_t id) : object(object), id(id) {
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getObjectById;
}

void GetSceneObject::execute() {
    this->object = ((*manager).*method)(id);
}
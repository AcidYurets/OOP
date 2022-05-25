#include <implementation/managers/manager_creator.hpp>
#include "count_models.hpp"

CountModels::CountModels(std::shared_ptr<size_t> &count) : count(count){
    this->manager = ManagerCreator<SceneManager>().getManager();
    this->method = &SceneManager::getModelsCount;
}

void CountModels::execute() {
    *(this->count) = ((*manager).*method)();
}
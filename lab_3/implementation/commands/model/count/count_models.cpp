#include <implementation/managers/manager_creator.hpp>
#include <implementation/facade/facade.hpp>
#include "count_models.hpp"

CountModels::CountModels(std::shared_ptr<size_t> &count) : count(count) {}

void CountModels::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::getModelsCount;
}

void CountModels::execute() {
    *(this->count) = ((*manager).*method)();
}
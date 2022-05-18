#include <implementation/managers/singleton.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "count_models.hpp"

CountModels::CountModels(std::shared_ptr<size_t> &count) : count(count) {}

void CountModels::execute() {
    *(this->count) = Singleton<SceneManager>::instance().getScene()->getModelsCount();
}


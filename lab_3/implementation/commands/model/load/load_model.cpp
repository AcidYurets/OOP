#include <implementation/managers/manager_creator.hpp>
#include "load_model.hpp"

LoadModel::LoadModel(std::shared_ptr<Object> &model, std::string filename) : filename(filename), model(model) {
    this->manager = ManagerCreator<LoadManager>().getManager();
    this->method = &LoadManager::load;
}

void LoadModel::execute() {
    model = ((*manager).*method)(filename, 2);
}
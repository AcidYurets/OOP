#include "wireframe_model_director.hpp"

WireframeModelDirector::WireframeModelDirector(std::shared_ptr<ObjectBuilder> builder) {
    this->builder = builder;
}

std::shared_ptr<Object> WireframeModelDirector::load(const std::string &src_name) {
    this->builder->reset();
    this->builder->assignFile(src_name);
    this->builder->buildPoints();
    this->builder->buildCenter();
    this->builder->buildEdges();
    this->builder->finishFileProcessing();
    decltype(auto) model = this->builder->get();

    return model;
}

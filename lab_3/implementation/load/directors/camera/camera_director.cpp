#include "camera_director.hpp"

CameraDirector::CameraDirector() {
    this->builder = std::make_shared<FileCameraBuilder>();
}

std::shared_ptr<Object> CameraDirector::load(const std::string &src_name) {
    this->builder->reset();
    this->builder->assignFile(src_name);
    this->builder->buildPosition();
    this->builder->finishFileProcessing();
    decltype(auto) camera = this->builder->get();

    return camera;
}

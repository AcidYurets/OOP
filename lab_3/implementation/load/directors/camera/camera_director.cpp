#include <implementation/load/solutions/camera/camera_load_solution.hpp>
#include "camera_director.hpp"

CameraDirector::CameraDirector(std::shared_ptr<ObjectBuilder> builder) {
    this->builder = builder;
}

std::shared_ptr<Object> CameraDirector::load(const std::string &src_name) {
    this->builder->reset();
    this->builder->assignFile(src_name);
    this->builder->buildPosition();
    this->builder->finishFileProcessing();
    decltype(auto) camera = this->builder->get();

    return camera;
}

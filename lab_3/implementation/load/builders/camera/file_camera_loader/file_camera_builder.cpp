#include "file_camera_builder.hpp"

#include <fstream>
#include <implementation/exceptions/load_exceptions.hpp>

FileCameraBuilder::FileCameraBuilder() : loader(std::make_shared<FileCameraLoader>()) {}

void FileCameraBuilder::assignFile(const std::string &src_name) {
    this->loader->openFile(src_name);
}

void FileCameraBuilder::finishFileProcessing() {
    this->loader->closeFile();
}

void FileCameraBuilder::reset() {
    this->camera = std::make_shared<Camera>();
}

std::shared_ptr<Object> FileCameraBuilder::get() {
    return this->camera;
}

void FileCameraBuilder::buildPosition() {
    Point pos = this->loader->loadPosition();
    this->camera->transform(pos, Point(1, 1, 1), Point(0, 0, 0));
}

#include "file_wireframe_model_builder.hpp"

#include <fstream>
#include <implementation/exceptions/load_exceptions.hpp>

FileWireframeModelBuilder::FileWireframeModelBuilder() : loader(std::make_shared<FileWireframeModelLoader>()) {}

void FileWireframeModelBuilder::assignFile(const std::string &src_name) {
    this->loader->openFile(src_name);
}

void FileWireframeModelBuilder::finishFileProcessing() {
    this->loader->closeFile();
}

void FileWireframeModelBuilder::reset() {
    this->model_details = std::make_shared<WireframeModelDetails>();
}

std::shared_ptr<Object> FileWireframeModelBuilder::get() {
    std::shared_ptr<Object> model = std::make_shared<WireframeModel>(this->model_details);
    return model;
}

void FileWireframeModelBuilder::buildPoints() {
    size_t points_count = this->loader->loadCount();

    for (size_t i = 0; i < points_count; i++) {
        Point p = this->loader->loadPoint();
        this->model_details->addPoint(p);
    }
}

void FileWireframeModelBuilder::buildEdges() {
    size_t points_count = this->loader->loadCount();

    for (size_t i = 0; i < points_count; i++) {
        Edge e = this->loader->loadEdge();
        this->model_details->addEdge(e);
    }
}

void FileWireframeModelBuilder::buildCenter() {
    Point c = this->loader->loadPoint();
    this->model_details->setCenter(c);
}

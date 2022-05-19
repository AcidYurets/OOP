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
    size_t points_count = this->loader->loadPointsCount();

    for (size_t i = 0; i < points_count; i++) {
        Point p = this->loader->loadPoint();
        this->model_details->addPoint(p);
    }
}

void FileWireframeModelBuilder::buildEdges() {
    size_t points_count = this->loader->loadEdgesCount();

    for (size_t i = 0; i < points_count; i++) {
        Edge e = this->loader->loadEdge();
        this->model_details->addEdge(e);
    }
}

void FileWireframeModelBuilder::buildCenter() {
    Point c = this->loader->loadPoint();
    this->model_details->setCenter(c);
}





















void FileWireframeModelBuilder::loadCenter() {
    double x, y, z;
    if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
    this->builder->buildCenter(Point(x, y, z));
}

void FileWireframeModelBuilder::loadPoints() {
    size_t points_count = 0;
    *(this->src_file) >> points_count;
    if (points_count <= 1) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    for (size_t i = 0; i < points_count; i++)
    {   double x, y, z;
        if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
        this->builder->buildPoint(Point(x, y, z));
    }
}

void FileWireframeModelBuilder::loadEdges() {
    size_t edges_count = 0;
    *(this->src_file) >> edges_count;
    if (edges_count < 1) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    for (size_t i = 0; i < edges_count; i++)
    {
        size_t p1_id, p2_id;
        if (!(*(this->src_file) >> p1_id >> p2_id)) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
        this->builder->buildEdge(Edge(p1_id, p2_id));
    }
}

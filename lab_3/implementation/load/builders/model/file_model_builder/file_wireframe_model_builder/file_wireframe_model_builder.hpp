#pragma once

#include <implementation/objects/model/wireframe_model/wireframe_model.hpp>
#include <implementation/load/loaders/model/file_wireframe_model_loader.hpp>
#include "../file_model_builder.hpp"

class FileWireframeModelBuilder : public FileModelBuilder {
public:
    FileWireframeModelBuilder();

    ~FileWireframeModelBuilder() = default;

    void assignFile(const std::string &src_name);

    void finishFileProcessing();

    void reset();

    std::shared_ptr<Object> get();

    void buildPoints();

    void buildEdges();
    
    void buildCenter();

    virtual void buildPosition() {}

private:
    std::shared_ptr<WireframeModelDetails> model_details;
    std::shared_ptr<FileWireframeModelLoader> loader;
};

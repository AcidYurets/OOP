#pragma once

#include <memory>
#include "implementation/objects/camera/camera.hpp"
#include <implementation/load/loaders/camera/file_camera_loader.hpp>
#include "../camera_builder.hpp"
//#include "implementation/objects/model/wireframe_model/model_details/point/point.hpp"

class FileCameraBuilder : public CameraBuilder {
public:
    FileCameraBuilder();

    ~FileCameraBuilder() = default;

    void assignFile(const std::string &src_name);

    void finishFileProcessing();

    void reset();

    std::shared_ptr<Object> get();

    void buildPosition();

    virtual void buildPoints() {}

    virtual void buildEdges() {}
    
    virtual void buildCenter() {}

private:
    std::shared_ptr<Camera> camera;
    std::shared_ptr<FileCameraLoader> loader;
};
#pragma once

#include <memory>
#include <fstream>
#include "implementation/objects/camera/camera.hpp"
#include "implementation/objects/model/wireframe_model/model_details/point/point.hpp"

class FileCameraLoader {
public:
    FileCameraLoader() = default;

    ~FileCameraLoader() = default;

    void openFile(const std::string &src_name);
    
    void closeFile();

    Point loadPosition();

private:
    std::shared_ptr<std::ifstream> src_file;
};

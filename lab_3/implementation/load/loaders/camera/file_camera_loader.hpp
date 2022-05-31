#pragma once

#include <memory>
#include <fstream>
#include "implementation/objects/camera/camera.hpp"
#include "implementation/objects/model/wireframe_model/model_details/point/point.hpp"
#include "implementation/load/loaders/file_base_loader.hpp"

class FileCameraLoader : public FileBaseLoader {
public:
    FileCameraLoader() = default;

    ~FileCameraLoader() = default;

    void openFile(const std::string &src_name);
    
    void closeFile();

    Point loadPoint();
    
    Edge loadEdge() { return Edge(0, 0); }

    size_t loadCount() { return 0; }

private:
    std::shared_ptr<std::ifstream> src_file;
};

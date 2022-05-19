//

//

#ifndef __LAB_03_CAMERA_BUILDER_HPP__
#define __LAB_03_CAMERA_BUILDER_HPP__


#include <memory>
#include "implementation/objects/camera/camera.hpp"
#include "implementation/objects/model/wireframe_model/model_details/point/point.hpp"

class CameraBuilder {
public:
    CameraBuilder();
    ~CameraBuilder() = default;

    [[nodiscard]] bool isBuild() const;
    void reset();
    void buildPosition(double x, double y, double z);

    std::shared_ptr<Camera> get();
private:
    std::shared_ptr<Camera> camera;
};


#endif //__LAB_03_CAMERA_BUILDER_HPP__

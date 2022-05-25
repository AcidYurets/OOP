#ifndef __LAB_03_ADD_CAMERA_HPP__
#define __LAB_03_ADD_CAMERA_HPP__

#include <memory>
#include <implementation/objects/object.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include "../camera_command.hpp"

class AddCamera : public CameraCommand {
    using Action = void(SceneManager::*)(const std::shared_ptr<Object> &);
public:
    AddCamera() = delete;

    AddCamera(double x_pos, double y_pos, double z_pos);

    ~AddCamera() override = default;

    void execute() override;

private:
    std::shared_ptr<Object> camera;
    Action method;
    std::shared_ptr<SceneManager> manager;
};


#endif //__LAB_03_ADD_CAMERA_HPP__

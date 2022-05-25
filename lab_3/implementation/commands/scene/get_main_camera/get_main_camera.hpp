#ifndef __LAB_03_GET_MAIN_CAMERA_HPP__
#define __LAB_03_GET_MAIN_CAMERA_HPP__

#include <cstddef>
#include "../scene_command.hpp"
#include <implementation/scene/scene.hpp>
#include <implementation/managers/scene/scene_manager.hpp>

class GetMainCamera : public SceneCommand {
    using Action = std::shared_ptr<Camera>(SceneManager::*)() const;
public:
    GetMainCamera() = delete;

    explicit GetMainCamera();

    ~GetMainCamera() override = default;

    void execute() override;

private:

    Action method;
    std::shared_ptr<SceneManager> manager;
};
#endif //__LAB_03_GET_MAIN_CAMERA_HPP__
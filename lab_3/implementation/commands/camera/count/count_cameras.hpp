#ifndef __LAB_03_COUNT_CAMERAS_HPP__
#define __LAB_03_COUNT_CAMERAS_HPP__

#include <memory>
#include <cstddef>

#include <implementation/commands/camera/camera_command.hpp>
#include <implementation/managers/scene/scene_manager.hpp>

class CountCameras : public CameraCommand {
    using Action = size_t(SceneManager::*)();
public:
    CountCameras() = delete;

    explicit CountCameras(std::shared_ptr<std::size_t> &count);

    ~CountCameras() override = default;

    void execute() override;

private:
    std::shared_ptr<std::size_t> &count;
    Action method;
    std::shared_ptr<SceneManager> manager;
};


#endif //__LAB_03_COUNT_CAMERAS_HPP__

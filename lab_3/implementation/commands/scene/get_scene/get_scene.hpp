#ifndef __LAB_03_GET_SCENE_HPP__
#define __LAB_03_GET_SCENE_HPP__

#include <cstddef>
#include "../scene_command.hpp"
#include <implementation/scene/scene.hpp>
#include <implementation/managers/scene/scene_manager.hpp>

class GetScene : public SceneCommand {
    using Action = std::shared_ptr<Scene>(SceneManager::*)() const;
public:
    GetScene() = delete;

    GetScene();

    ~GetScene() override = default;

    void execute() override;

private:
    Action method;
    std::shared_ptr<SceneManager> manager;
};
#endif //__LAB_03_GET_SCENE_HPP__
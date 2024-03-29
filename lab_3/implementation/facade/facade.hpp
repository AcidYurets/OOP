#ifndef __LAB_03_FACADE_HPP__
#define __LAB_03_FACADE_HPP__


#include <memory>
#include "implementation/commands/command.hpp"
#include <implementation/managers/load/load_manager.hpp>
#include <implementation/managers/draw/draw_manager.hpp>
#include <implementation/managers/transform/transform_manager.hpp>
#include <implementation/managers/scene/scene_manager.hpp>

class Facade {
public:
    Facade();
    void execute(const std::shared_ptr<Command> &command);
    
    std::shared_ptr<LoadManager> getLoadManager();
    std::shared_ptr<DrawManager> getDrawManager();
    std::shared_ptr<TransformManager> getTransformManager();
    std::shared_ptr<SceneManager> getSceneManager();
private:
    std::shared_ptr<LoadManager> loadManager;
    std::shared_ptr<DrawManager> drawManager;
    std::shared_ptr<TransformManager> transformManager;
    std::shared_ptr<SceneManager> sceneManager;
};


#endif //__LAB_03_FACADE_HPP__

#ifndef __LAB_03_FACADE_HPP__
#define __LAB_03_FACADE_HPP__


#include <memory>
#include <qdebug>
#include "implementation/commands/command.hpp"

class Facade {
public:
    Facade() {
        // ManagerSolution solution;

        // solution.registration<DrawManager>("draw");

        // std::shared_ptr<Creator> = solution.createCreator("draw");

        std::shared_ptr<Creator> draw_cr = std::make_shared<ManagerCreator<DrawManager>>();

        draw_manager = draw_cr.getManager();
        // ...
    }
    void execute(const std::shared_ptr<Command> &command);

    std::shared_ptr<DrawManager> getDrawManager();

private:
    ptr DrawManager draw_manager;
    ptr TransformManager transform_manager;
    ptr SceneManager scene_manager;
    ptr LoadManager load_manager;
};


#endif //__LAB_03_FACADE_HPP__

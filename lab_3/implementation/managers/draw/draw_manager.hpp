#ifndef __LAB_03_DRAW_MANAGER_HPP__
#define __LAB_03_DRAW_MANAGER_HPP__


#include "implementation/managers/manager.hpp"
#include "implementation/managers/load/load_manager.hpp"
#include "implementation/objects/model/model_details/point/point.hpp"
#include "implementation/objects/model/model.hpp"
#include "implementation/objects/camera/camera.hpp"
#include "implementation/visitor/visitor.hpp"

class DrawManager : public Manager {
public:
    DrawManager() = default;

    DrawManager(const DrawManager &) = delete;

    DrawManager &operator=(const DrawManager &) = delete;

    ~DrawManager() override = default;

    void draw(const std::shared_ptr<Scene> &scene);

    void setDrawer(std::shared_ptr<Drawer> drawer);

    void setCamera(std::shared_ptr<Camera> camera);

private:
    std::shared_ptr<Drawer> drawer;
    std::shared_ptr<Camera> camera;
};

#endif //__LAB_03_DRAW_MANAGER_HPP__

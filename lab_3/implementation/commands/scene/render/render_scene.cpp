#include <implementation/managers/manager_creator.hpp>
#include <utility>
#include "render_scene.hpp"

RenderScene::RenderScene(std::shared_ptr<Scene> &scene, std::shared_ptr<Drawer> drawer, std::shared_ptr<Camera> mainCamera) 
                                    : scene(scene), drawer(drawer), mainCamera(mainCamera) {
    this->manager = ManagerCreator<DrawManager>().getManager();
    this->method = &DrawManager::draw;
}

void RenderScene::execute() {
    ((*manager).*method)(scene, drawer, mainCamera);
}

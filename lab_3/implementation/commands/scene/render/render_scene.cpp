#include <implementation/managers/singleton.hpp>
#include <implementation/managers/draw/draw_manager.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <utility>
#include "render_scene.hpp"

RenderScene::RenderScene(std::shared_ptr<Drawer> drawer) : drawer(std::move(drawer)) {}

void RenderScene::execute() {
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();
    decltype(auto) draw_manager = Singleton<DrawManager>::instance();

    draw_manager.setCamera(scene_manager.getMainCamera());
    draw_manager.setDrawer(this->drawer);

    this->drawer->clearScene();

    draw_manager.draw(scene_manager.getScene());
}

#include <utility>
#include <memory>

#include "draw_manager.hpp"
#include "implementation/scene/scene.hpp"
#include "implementation/visitor/draw_visitor/draw_visitor.hpp"

void DrawManager::setDrawer(std::shared_ptr<Drawer> drawer) {
    this->drawer = std::move(drawer);
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera) {
    this->camera = std::move(camera);
}

void DrawManager::draw(const std::shared_ptr<Scene> &scene) {
    auto visitor = std::make_shared<DrawVisitor>(this->drawer, this->camera);
    scene->accept(visitor);
}

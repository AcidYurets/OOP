#include <implementation/managers/singleton.hpp>
#include <implementation/managers/load/load_manager.hpp>
#include <implementation/managers/scene/scene_manager.hpp>
#include <implementation/load/directors/camera/camera_director.hpp>
#include <implementation/load/builders/camera/file_camera_builder/file_camera_builder.hpp>
#include "load_camera.hpp"

LoadCamera::LoadCamera(std::string filename) : filename(std::move(filename)) {}

void LoadCamera::execute() {
    decltype(auto) load_manager = Singleton<LoadManager>::instance();
    decltype(auto) scene_manager = Singleton<SceneManager>::instance();

    decltype(auto) builder = std::make_shared<FileCameraBuilder>();
    decltype(auto) director = std::make_shared<CameraDirector>(builder);
    load_manager.setDirector(director);

    decltype(auto) camera = load_manager.load(filename);
    scene_manager.getScene()->addObject(camera);
}

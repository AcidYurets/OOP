//

//

#ifndef __LAB_03_SCENE_BUILDER_HPP__
#define __LAB_03_SCENE_BUILDER_HPP__

#include <memory>
#include <implementation/objects/object.hpp>
#include "implementation/scene/scene.hpp"

class SceneBuilder {
public:
    SceneBuilder();

    ~SceneBuilder() = default;

    [[nodiscard]] bool isBuild() const;

    void reset();

    void buildModel(const std::shared_ptr<Object> &model);

    void buildCamera(const std::shared_ptr<Object> &camera);

    std::shared_ptr<Scene> get();

private:
    std::shared_ptr<Scene> scene;
};


#endif //__LAB_03_SCENE_BUILDER_HPP__

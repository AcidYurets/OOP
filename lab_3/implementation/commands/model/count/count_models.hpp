#ifndef __LAB_03_COUNT_MODELS_HPP__
#define __LAB_03_COUNT_MODELS_HPP__

#include <memory>
#include <cstddef>

#include "implementation/commands/model/model_command.hpp"
#include <implementation/managers/scene/scene_manager.hpp>


class CountModels : public ModelCommand {
    using Action = size_t(SceneManager::*)() const;
public:
    CountModels() = delete;

    explicit CountModels(std::shared_ptr<size_t> &count);

    ~CountModels() override = default;

    void execute() override;

private:
    std::shared_ptr<std::size_t> &count;
    Action method;
    std::shared_ptr<SceneManager> manager;
};

#endif //__LAB_03_COUNT_MODELS_HPP__

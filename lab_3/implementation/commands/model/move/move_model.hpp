#ifndef __LAB_03_MOVE_MODEL_HPP__
#define __LAB_03_MOVE_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"
#include <implementation/objects/object.hpp>
#include <implementation/managers/transform/transform_manager.hpp>

class MoveModel : public ModelCommand {
    using Action = void(TransformManager::*)(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                        const Point &rotate_params);
public:
    MoveModel() = delete;

    MoveModel(std::shared_ptr<Object> model, double dx, double dy, double dz);

    ~MoveModel() override = default;

    void execute() override;

private:
    std::shared_ptr<Object> model;

    double dx, dy, dz;
    Action method;
    std::shared_ptr<TransformManager> manager;
};



#endif //__LAB_03_MOVE_MODEL_HPP__

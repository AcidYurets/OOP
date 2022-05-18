#ifndef __LAB_03_TRANSFORM_MANAGER_HPP__
#define __LAB_03_TRANSFORM_MANAGER_HPP__


#include "implementation/objects/model/model_details/point/point.hpp"
#include "implementation/objects/object.hpp"
#include "implementation/managers/manager.hpp"

class TransformManager : public Manager {
public:
    TransformManager() = default;

    TransformManager(const TransformManager &) = delete;

    TransformManager &operator=(const TransformManager &) = delete;

    ~TransformManager() override = default;

    static void transform(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                          const Point &rotate_params);

};

#endif //__LAB_03_TRANSFORM_MANAGER_HPP__

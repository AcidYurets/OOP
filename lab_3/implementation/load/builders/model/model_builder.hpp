//
// Created by ivaaahn on 28.05.2021.
//

#ifndef __LAB_03_MODEL_BUILDER_HPP__
#define __LAB_03_MODEL_BUILDER_HPP__


#include <vector>
#include <implementation/objects/model/model_details/point/point.hpp>
#include <implementation/objects/model/model_details/edge/edge.hpp>
#include <memory>
#include <implementation/objects/model/model.hpp>

class ModelBuilder {
public:
    ModelBuilder();

    ~ModelBuilder() = default;

    bool isBuild();

    void reset();

    void buildCenter(const Point &point);

    void buildPoint(const Point &point);

    void buildEdge(const Edge &edge);

    std::shared_ptr<Model> get();

private:
    std::shared_ptr<ModelDetails> model_details;
};


#endif //__LAB_03_MODEL_BUILDER_HPP__

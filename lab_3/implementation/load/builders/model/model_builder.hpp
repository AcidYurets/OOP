#pragma once

#include "../object_builder.hpp"

class ModelBuilder : public ObjectBuilder {
public:
    ModelBuilder() = default;

    virtual ~ModelBuilder() = default;

    virtual void assignFile(const std::string &src_name) = 0;

    virtual void finishFileProcessing() = 0;

    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void buildPoints() = 0;

    virtual void buildEdges() = 0;
    
    virtual void buildCenter() = 0;
};

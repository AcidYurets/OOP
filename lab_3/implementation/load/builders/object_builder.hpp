#pragma once

#include <string>
#include <implementation/objects/object.hpp>

class ObjectBuilder {
public:
    ObjectBuilder() = default;

    virtual ~ObjectBuilder() = default;

    virtual void assignFile(const std::string &src_name) = 0;

    virtual void finishFileProcessing() = 0;

    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void buildPoints() = 0;

    virtual void buildEdges() = 0;
    
    virtual void buildCenter() = 0;

    virtual void buildPosition() = 0;
};

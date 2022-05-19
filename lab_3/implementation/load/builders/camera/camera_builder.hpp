#pragma once

#include "../object_builder.hpp"
#include "../../../objects/object.hpp"

class CameraBuilder : public ObjectBuilder {
public:
    CameraBuilder() = default;

    virtual ~CameraBuilder() = default;

    virtual void assignFile(const std::string &src_name) = 0;

    virtual void finishFileProcessing() = 0;

    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void buildPosition() = 0;
};

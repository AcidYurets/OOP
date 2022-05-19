#pragma once

#include "../model_builder.hpp"

class FileModelBuilder : public ModelBuilder {
public:
    FileModelBuilder() = default;

    virtual ~FileModelBuilder() = default;

    virtual void assignFile(const std::string &src_name) = 0;

    virtual void finishFileProcessing() = 0;

    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void buildPoints() = 0;

    virtual void buildEdges() = 0;
    
    virtual void buildCenter() = 0;
};

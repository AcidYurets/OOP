#ifndef __LAB_03_ADD_MODEL_HPP__
#define __LAB_03_ADD_MODEL_HPP__

#include <memory>
#include <implementation/objects/object.hpp>
#include "../model_command.hpp"

class AddModel : public ModelCommand {
public:
    AddModel() = delete;

    explicit AddModel(std::shared_ptr<Object> model);

    ~AddModel() override = default;

    void execute() override;

private:
    std::shared_ptr<Object> model;
};


#endif //__LAB_03_ADD_MODEL_HPP__

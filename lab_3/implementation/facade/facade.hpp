#ifndef __LAB_03_FACADE_HPP__
#define __LAB_03_FACADE_HPP__


#include <memory>
#include <qdebug>
#include "implementation/commands/command.hpp"

class Facade {
public:
    void execute(const std::shared_ptr<Command> &command);
};


#endif //__LAB_03_FACADE_HPP__

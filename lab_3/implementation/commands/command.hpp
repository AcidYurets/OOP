#ifndef __LAB_03_COMMAND_HPP__
#define __LAB_03_COMMAND_HPP__

#include <implementation/facade/facade.hpp>

class Command {
public:
    Command() = default;

    virtual ~Command() = default;

    virtual void init(Facade &facade) = 0;

    virtual void execute() = 0;
};

#endif //__LAB_03_COMMAND_HPP__

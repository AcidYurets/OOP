#include "facade.hpp"

void Facade::execute(const std::shared_ptr<Command> &command) {
    command->init(*this);
    command->execute();
}

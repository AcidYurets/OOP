#include "facade.hpp"

void Facade::execute(const std::shared_ptr<Command> &command) {
    command->execute();
}

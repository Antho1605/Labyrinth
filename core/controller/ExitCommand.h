#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Represents a command of the game.
 */
class ExitCommand : public Command {

public:

    ExitCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        exit(0);
    }

    ~ExitCommand() override = default;

};

}}

#endif

#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Represents a command of the game.
 */
class HelpCommand : public Command {

public:

    HelpCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        view_.printHelp();
    }

    ~HelpCommand() override = default;

};

}}

#endif

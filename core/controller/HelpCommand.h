#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Prints the list of commands annd their decription when executed.
 */
class HelpCommand : public Command {

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
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

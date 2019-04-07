#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Exits the game when executed.
 */
class ExitCommand : public Command {

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
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

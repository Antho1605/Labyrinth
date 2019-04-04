#ifndef PASSMOVECOMMAND_H
#define PASSMOVECOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Represents a command of the game.
 */
class PassMoveCommand : public Command {

public:

    PassMoveCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        game_->getCurrentPlayer().setDone();
        view_.print("You decided not to move your piece!");
    }

    ~PassMoveCommand() override = default;

};

}}

#endif

#ifndef PASSMOVECOMMAND_H
#define PASSMOVECOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Passes the move of the current player when executed.
 */
class PassMoveCommand : public Command {

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
    PassMoveCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        game_->getCurrentPlayer().setDone();
        view_.print("You decided not to move your piece!");
        game_->nextPlayer();
    }

    ~PassMoveCommand() override = default;

};

}}

#endif

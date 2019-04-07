#ifndef MOVECURRENTPLAYERCOMMAND_H
#define MOVECURRENTPLAYERCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Moves the current player card at the given position int the maze
 * when executed.
 */
class MovePlayerCommand : public Command {

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
    MovePlayerCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        if (argv_.size() < 3) throw std::logic_error("usage: move row column");
        unsigned row = std::stoul(argv_[1]);
        unsigned column = std::stoul(argv_[2]);
        game_->selectPlayerPosition(model::MazePosition{row, column});
        game_->moveCurrentPlayer();
        if (game_->hasCurrentPlayerFoundObjective()) {
            game_->getCurrentPlayer().turnCurrentObjectiveOver();
            game_->getCurrentPlayer().nextObjective();
            view_.print("You have found an objective!\n");
        }
        game_->nextPlayer();
        view_.printMaze();
    }

    ~MovePlayerCommand() override = default;

};

}}

#endif

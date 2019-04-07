#ifndef MOVECURRENTPLAYERCOMMAND_H
#define MOVECURRENTPLAYERCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Represents a command of the game.
 */
class MovePlayerCommand : public Command {

public:

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
            view_.print("You have found an objective!");
        }
        game_->nextPlayer();
        view_.printMaze();
    }

    ~MovePlayerCommand() override = default;

};

}}

#endif

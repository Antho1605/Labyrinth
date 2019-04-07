#ifndef INSERTCOMMAND_H
#define INSERTCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Inserts the current maze card at the given position int the maze
 * when executed.
 */
class InsertCommand : public Command {

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
    InsertCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        if (argv_.size() < 3) throw std::logic_error("usage: insert row column");
        unsigned row = static_cast<unsigned>(std::stoul(argv_[1]));
        unsigned column = static_cast<unsigned>(std::stoul(argv_[2]));
        game_->selectInsertionPosition(model::MazePosition{row, column});
        game_->movePathWays();
        view_.printMaze();
    }

    ~InsertCommand() override = default;

};

}}

#endif

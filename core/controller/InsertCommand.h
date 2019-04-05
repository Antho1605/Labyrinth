#ifndef INSERTCOMMAND_H
#define INSERTCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Represents a command of the game.
 */
class InsertCommand : public Command {

public:

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

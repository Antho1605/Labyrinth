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

    InsertCommand(labyrinth::view::View & view, Game &game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        if (argv_.size() < 3) throw std::logic_error("usage: insert row column");
        unsigned row = std::stoul(argv_[1]);
        unsigned column = std::stoul(argv_[2]);
        game_.selectInsertionPosition(MazePosition{row, column});
        game_.movePathWays();
        view_.printMaze();
    }

    ~InsertCommand() override = default;

};

}}

#endif

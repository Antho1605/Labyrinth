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

    MovePlayerCommand(labyrinth::view::View & view, Game &game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        if (argv_.size() < 3) throw std::logic_error("usage: move row column");
        unsigned row = std::stoul(argv_[1]);
        unsigned column = std::stoul(argv_[2]);
        game_.selectPlayerPosition(MazePosition{row - 1, column - 1});
        game_.moveCurrentPlayer();
    }

    ~MovePlayerCommand() override = default;

};

}}

#endif

#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Rotates the current maze card the number of times given by the user
 * when executed.
 */
class RotateCommand : public Command {

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
    RotateCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        if (argv_.size() < 2)
            throw std::logic_error("usage: rotate <number of times>");
        unsigned ntimes = std::stoul(argv_[1]);
        if (ntimes > 10)
            throw std::invalid_argument("Only 10 rotations are allowed.");
        for (unsigned i = 0; i < ntimes; ++i) game_->getCurrentMazeCard().rotate();
        view_.print("You have rotated the current maze card " + std::to_string(ntimes) + ".");
        view_.printCurrentMazeCard();
    }

    ~RotateCommand() override = default;

};

}}

#endif

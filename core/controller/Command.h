#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "Game.h"
#include "View.h"

namespace labyrinth { namespace controller {

/**
 * @brief Represents a command of the game.
 */
class Command {

protected:

    /**
     * @brief Is the view representing the game.
     */
    view::View view_;

    /**
     * @brief Is the game to control.
     */
    model::Game *game_;

    /**
     * @brief Are the arguments of this command.
     */
    std::vector<std::string> argv_;

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
    Command(view::View & view, model::Game *game)
        : view_{view},
          game_{game}
    {}

    /**
     * @brief Sets this command arguments. The first argument os the list is
     * the command name.
     *
     * @param argv is the list of arguments.
     */
    virtual void setArguments(const std::vector<std::string> &argv) { argv_ = argv; }

    /**
     * @brief Executes this command.
     */
    virtual void execute() = 0;

    virtual ~Command() = 0;

};

inline Command::~Command() {}

}}

#endif

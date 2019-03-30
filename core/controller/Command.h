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

    labyrinth::view::View view_;
    labyrinth::Game game_;
    std::vector<std::string> argv_;

public:

    Command(labyrinth::view::View & view, Game &game)
        : view_{view},
          game_{game}
    {}

    virtual void setArguments(const std::vector<std::string> &argv) { argv_ = argv; }

    /**
     * @brief Executes this command
     */
    virtual void execute() = 0;

    virtual ~Command() = 0;

};

inline Command::~Command() {}

}}

#endif

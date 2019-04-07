#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <string>
#include <memory>
#include <map>

#include "Game.h"
#include "View.h"
#include "Command.h"
#include "CommandType.h"
#include "HelpCommand.h"
#include "MovePlayerCommand.h"
#include "ShowCommand.h"
#include "InsertCommand.h"
#include "RotateCommand.h"
#include "PassMoveCommand.h"
#include "ExitCommand.h"

namespace labyrinth { namespace controller {

/**
 * @brief This class is used to construct all the different types of commands for
 * this game.
 */
class CommandFactory {

    /**
     * @brief Is the view used to represent the game.
     */
    labyrinth::view::View view_;

    /**
     * @brief Is the game to execute the constructed command on.
     */
    labyrinth::model::Game *game_;

public:

    /**
     * @brief Constructs this command factory with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
    CommandFactory(const labyrinth::view::View & view, model::Game *game)
        : view_{view},
          game_{game}
     {}

    /**
     * @brief Constructs a command of the given type.
     *
     * @param type is the type of the command to construct.
     * @return a command of the given type.
     */
    Command *getCommand(const CommandType &type)
    {
        switch (type)
        {
        case HELP:
            return new HelpCommand(view_, game_);
        case MOVE:
            return new MovePlayerCommand(view_, game_);
        case SHOW:
            return new ShowCommand(view_, game_);
        case INSERT:
            return new InsertCommand(view_, game_);
        case ROTATE:
            return new RotateCommand(view_, game_);
        case PASS:
            return new PassMoveCommand(view_, game_);
        case EXIT:
            return new ExitCommand(view_, game_);
        default:
            throw std::invalid_argument("The type of command is not defined.");
        }
    }

};

}}

#endif

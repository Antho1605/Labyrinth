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

class CommandFactory {

    labyrinth::view::View view_;
    labyrinth::Game *game_;

public:

    CommandFactory(const labyrinth::view::View & view, Game *game)
        : view_{view},
          game_{game}
     {}

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
        }
    }

};

}}

#endif

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
#include "ExitCommand.h"

namespace labyrinth { namespace controller {

class CommandFactory {

    labyrinth::view::View view_;
    labyrinth::Game game_;

public:

    CommandFactory(const labyrinth::view::View & view, Game game)
        : view_{view},
          game_{game}
     {}

    const std::unique_ptr<Command> getCommand(const CommandType &type)
    {
        switch (type)
        {
        case HELP:
            return std::make_unique<HelpCommand>(view_, game_);
        case EXIT:
            return std::make_unique<ExitCommand>(view_, game_);
        }
    }

};

}}

#endif

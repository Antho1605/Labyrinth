#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "Game.h"
#include "View.h"
#include "CommandType.h"
#include "CommandFactory.h"

namespace labyrinth { namespace controller {

class Controller {

    labyrinth::view::View view_;
    labyrinth::Game game_;

public:

    Controller(const labyrinth::view::View &view, labyrinth::Game game)
        : view_{view},
          game_{game}
    {}

    void start() const {
        CommandFactory factory(view_, game_);
        view_.printTitle();
        while (1) {
            std::string command = view_.readCommand("> ");
            factory.getCommand(fromString(command)).get()->execute();
        }
    }

};

}}

#endif

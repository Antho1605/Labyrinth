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

    /**
     * @brief Executes the command represented by argv.
     * @param argv first string is the name of the command to execute. The
     * command arguments are the other strings.
     */
    void execute(const std::vector<std::string> &argv) const
    {
        CommandFactory factory(view_, game_);
        try {
            if (!argv.empty()) {
                CommandType type = fromString(argv.at(0));
                factory.getCommand(type).get()->execute();
            }
        } catch (std::exception e) {
            view_.print("Invalid command! Try again or type 'help' to list the commands");
        }
    }

    void start() const {
        view_.printTitle();
        while (!game_.isOver()) {
            std::vector<std::string> argv = view_.readCommand("> ");
            execute(argv);
        }
    }

};

}}

#endif

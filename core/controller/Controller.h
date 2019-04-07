#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "Game.h"
#include "View.h"
#include "CommandType.h"
#include "CommandFactory.h"

namespace labyrinth { namespace controller {

/**
 * @brief Manages the logic of the game.
 */
class Controller {

    /**
     * @brief Is the view used to represent the game.
     */
    labyrinth::view::View view_;

    /**
     * @brief Is the game to represent.
     */
    labyrinth::model::Game *game_;

public:

    /**
     * @brief Constructs this controller.
     *
     * @param view is the view used to represent the game.
     * @param game is a pointer to the game to control.
     */
    Controller(const labyrinth::view::View &view, labyrinth::model::Game *game)
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
                Command *command = factory.getCommand(type);
                command->setArguments(argv);
                command->execute();
                delete command;
            }
        } catch (std::logic_error e) {
            view_.print(e.what());
        }
    }

    /**
     * @brief Starts a game.
     */
    void start() const {
        view_.printTitle();
        view_.printMaze();
        while (!game_->isOver()) {
            std::vector<std::string> argv = view_.readCommand();
            execute(argv);
        }
        view_.printWinner();
    }

};

}}

#endif

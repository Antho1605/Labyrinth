#include <iostream>
#include <string>

#include "Game.h"
#include "View.h"
#include "Controller.h"

using namespace labyrinth::view;
using namespace labyrinth::controller;
using namespace labyrinth::model;

/**
 * @brief Start a game of Labyrinth.
 */
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "usage: ./labyrinth <number of players>\n";
        exit(1);
    }
    try {
        unsigned nplayers = std::stoul(argv[1]);
        if (nplayers < Game::MIN_NB_OF_PLAYERS || Game::MAX_NB_OF_PLAYERS < nplayers) {
            std::cerr << "usage: the number of players should be positive and between 2 and 4.\n";
            exit(2);
        }
        Game game{nplayers};
        View view{&game};
        Controller controller{view, &game};
        controller.start();
    } catch (std::exception e) {
        std::cerr << "usage: the number of players should be a positive number between 2 and 4\n";
    }
    return 0;
}

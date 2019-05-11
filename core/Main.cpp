#include <QApplication>

#include <iostream>
#include <string>
#include <cstring>

#include "Game.h"
#include "View.h"
#include "Controller.h"
#include "GameWindow.h"

using namespace labyrinth::view;
using namespace labyrinth::controller;
using namespace labyrinth::model;

static const char * option = "simplified";

/**
 * @brief Start a game of Labyrinth.
 */
int main(int argc, char **argv) {

    if (argc < 3) {
        std::cerr << "usage: ./labyrinth <-c or -g> <number of players> [simplified]\n";
        exit(1);
    }

    bool isSimplified = false;
    unsigned nplayers = std::stoul(argv[2]);

    if (nplayers < Game::MIN_NB_OF_PLAYERS || Game::MAX_NB_OF_PLAYERS < nplayers) {
        std::cerr << "usage: the number of players should be positive and between 2 and 4.\n";
        exit(2);
    }

    if (argc == 4 && std::strcmp(argv[3], option) == 0) {
        isSimplified = true;
    }

    Game game{nplayers, isSimplified};

    if (std::strcmp(argv[1], "-g") == 0) {
        QApplication core(argc, argv);
        GameWindow main{&game};
        game.registerObserver(&main);
        main.show();
        return core.exec();
    } else if (std::strcmp(argv[1], "-c") == 0) {
        try {
            View view{&game};
            Controller controller{view, &game};
            controller.start();
        } catch (const std::exception &e) {
            std::cerr << "usage: the number of players should be a positive number between 2 and 4\n";
        }
        return 0;
    }

}

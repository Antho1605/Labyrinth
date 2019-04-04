#include <iostream>

#include "Game.h"
#include "View.h"
#include "Controller.h"

using namespace labyrinth::view;
using namespace labyrinth::controller;
using namespace labyrinth::model;

/**
 * @brief Start a game of Labyrinth.
 */
int main() {
    Game game{4};
    View view{&game};
    Controller controller{view, &game};
    controller.start();
    return 0;
}

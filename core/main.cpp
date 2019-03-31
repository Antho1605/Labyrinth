#include <iostream>

#include "Game.h"
#include "View.h"
#include "Controller.h"

using namespace labyrinth::view;
using namespace labyrinth::controller;
using namespace labyrinth;

int main() {
    Game g{4};
    View v{g};
    Controller c{v, g};
    c.start();
}

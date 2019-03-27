#include <iostream>

#include "Output.h"
#include "Game.h"

using namespace labyrinth::view;
using namespace labyrinth;

int main() {
    std::cout << "Labyrinth entry point." << std::endl;
    Output out{Game(2), std::cout};
    MazeCard m{UP | DOWN, true};
    out.printMaze();
}

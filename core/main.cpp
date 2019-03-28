#include <iostream>

#include "Output.h"
#include "Game.h"
#include "tostring.h"

using namespace labyrinth::view;
using namespace labyrinth;

int main() {
    std::cout << "Labyrinth entry point." << std::endl;
    Output out{Game(2), std::cout};
    MazeCard m{UP | DOWN, true};
    Player p{Player::Color::BLUE, 7, MazePosition(), {Object::BAT,
                    Object::BONES, Object::BUTTERFLY, Object::GHOST,
                    Object::DRAGON, Object::MAP}};
    std::cout << toString(p);
    out.printMaze();
}

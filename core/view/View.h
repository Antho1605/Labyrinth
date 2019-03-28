#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Output.h"
#include "Game.h"

namespace labyrinth { namespace view {

class View
{
    Output out;

public:

    /**
     * @brief Constructs this view with the game to represent.
     * @param game is the game to represent.
     */
    View(const Game &game)
        : out{game}
    {}

    /**
     * @brief Prints the current state of the game maze.
     */
    void printMaze() const { out.printMaze(); }

    void printPlayers() const { out.printPlayers(); }

};

}}

#endif // VIEW_H

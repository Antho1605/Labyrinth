#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>

#include "Game.h"

namespace labyrinth { namespace view {

class Output
{

    Game game_;
    const std::ostream &out_;

public:

    /**
     * @brief Constructs this output.
     *
     * @param game is the game to make output for.
     * @param out is the output stream to output to.
     */
    Output(const Game &game, const std::ostream &out)
        : game_{game}, out_{out}
    {}

    /**
     * @brief Prints the current state of the game maze.
     */
    void printMaze() const;

    /**
     * @brief Prints all the playing taking part to the game.
     */
    void printPlayers() const;

    /**
     * @brief Prints the last maze card that has been pushed out of the game
     * maze.
     */
    void printLastPushedOutMazeCard() const;

};

}}


#endif // OUTPUT_H

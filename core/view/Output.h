#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>

#include "Game.h"

namespace labyrinth { namespace view {

class Output
{

    const Game *game_;
    std::ostream &out_;

public:

    /**
     * @brief Constructs this output.
     *
     * @param game is the game to make output for.
     * @param out is the output stream to output to.
     */
    Output(const Game *game, std::ostream &out)
        : game_{game}, out_{out}
    {}

    void print(std::string str) const;

    void printTitle() const;

    void printHelp() const;

    void printPrompt() const;

    void printUpperInsertionIcons() const;

    void printDownInsertionIcons() const;

    void printColumnCoordinate() const;

    void printMazeCardPart(const MazeCard &, unsigned, std::string) const;

    std::string getCenterString() const;

    void printMazeCardPartsRow(unsigned mazeRow, unsigned part) const;

    void printPlayer(const Player &p) const;

    /**
     * @brief Prints the current state of the game maze.
     */
    void printMaze() const;

    /**
     * @brief Prints all the playing taking part to the game.
     */
    void printPlayers() const;

    /**
     * @brief Prints the objectives in the maze and their position.
     */
    void printMazeObjectives() const;

    /**
     * @brief Prints the current player current objective.
     */
    void printCurrentPlayerObjective() const;

    /**
     * @brief Prints the last maze card that has been pushed out of the game
     * maze.
     */
    void printCurrentMazeCard() const;

};

}}


#endif // OUTPUT_H

#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>

#include "Game.h"

namespace labyrinth { namespace view {

/**
 * @brief Manages all the output of the view.
 */
class Output
{

    const model::Game *game_;
    std::ostream &out_;

    void printUpperInsertionIcons() const;

    void printDownInsertionIcons() const;

    void printColumnCoordinate() const;

    void printMazeCardPart(const model::MazeCard &, unsigned, std::string) const;

    std::string getCenterString() const;

    void printMazeCardPartsRow(unsigned mazeRow, unsigned part) const;

public:

    /**
     * @brief Constructs this output.
     *
     * @param game is a pointer to the game to make output for.
     * @param out is the output stream to output to.
     */
    Output(const model::Game *game, std::ostream &out)
        : game_{game}, out_{out}
    {}

    /**
     * @brief prints the given message and adds a next line characters to the end
     * of it.
     *
     * @param str is the message to print.
     */
    void print(std::string str) const;

    /**
     * @brief Prints the title of the game and the help menu.
     */
    void printTitle() const;

    /**
     * @brief Prints the help menu. The help menu contains the list of available
     * commands and their description.
     */
    void printHelp() const;

    /**
     * @brief Prints the prompt. The prompts tells who is the current player.
     */
    void printPrompt() const;

    /**
     * @brief Prints the given player.
     *
     * @param p is the player to print.
     */
    void printPlayer(const model::Player &p) const;

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

    /**
     * @brief Prints the end of the game.
     */
    void printEnd() const;

};

}}


#endif // OUTPUT_H

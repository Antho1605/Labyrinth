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
    View(const Game *game)
        : out{game, std::cout}
    {}

    void print(std::string msg) const { out.print(msg); }

    /**
     * @brief Prints the title of the game.
     */
    void printTitle() const { out.printTitle(); }

    /**
     * @brief Prints the list of commands of this game.
     */
    void printHelp() const { out.printHelp(); }

    /**
     * @brief Prints the current state of the game maze.
     */
    void printMaze() const { out.printMaze(); }

    /**
     * @brief Prints the players taking part to the game.
     */
    void printPlayers() const { out.printPlayers(); }

    /**
     * @brief Prints the objectives in the maze and their position.
     */
    void printMazeObjectives() const {
        out.printMazeObjectives();
    }

    /**
     * @brief Prints the current player current objective.
     */
    void printCurrentPlayerObjective() const {
        out.printCurrentPlayerObjective();
    }

    /**
     * @brief Prints the last maze card that has been pushed out of the game
     * maze.
     */
    void printCurrentMazeCard() const { out.printCurrentMazeCard(); }

    /**
     * @brief Reads a coordinate from the user. A coordinate should be between
     * 1 and 7.
     *
     * @param msg is the message that prompts the user.
     * @return the coordinate entered by the user.
     */
    unsigned readCoordinate(std::string msg) const;

    /**
     * @brief Reads an age from a user. An age should be smaller than 200.
     *
     * @param msg is the message that prompts the user.
     * @return the age entered by the user.
     */
    unsigned readAge(std::string msg) const;

    /**
     * @brief Reads a command from a user.
     *
     * @param msg is the message that prompts the user.
     * @return a command entered by a user.
     */
    std::vector<std::string> readCommand(std::string msg) const;

};

}}

#endif // VIEW_H

#ifndef MAZE_H
#define MAZE_H

#include <map>
#include <vector>
#include <deque>

#include "MazePosition.h"
#include "MazeCard.h"

namespace labyrinth {

/**
 * @brief Represents the maze of the game.
 */
class Maze
{

private:

    /**
     * @brief Is the last maze card that has been inserted in this maze. It is
     * not possible to insert aa new maze card at its position.
     */
    MazeCard lastMazeCardInserted_;

    /**
     * @brief Represents the adjacencies of this maze cards.
     */
    typedef std::map<MazePosition, std::vector<MazePosition>> Graph;
    Graph adjacencies_;

    /**
     * @brief are the cards inside of this maze.
     */
    std::deque<std::deque<MazeCard>> cards_;

    void updateAdjacency();

public:

    static unsigned SIZE;

    Maze() = default;

    void initialize();

    /**
     * @brief Gets the card located at the given position.
     *
     * @param position is the position of the card to get.
     * @return the card at the given position.
     */
    const MazeCard &getCardAt(const MazePosition &position) const {
        return cards_.at(position.getRow()).at(position.getColumn());
    }

    /**
     * @brief Tells if the maze cards at the given positions are neighbors.
     *
     * Two maze cards are neighbors when the first maze card is directly
     * reachable by the second one and vice-versa.
     *
     * @param lhs is the first maze card.
     * @param rhs is the second maze card.
     * @return true if the two maze cards at the given positions are neighbors.
     */
    bool areAdjacent(const MazePosition &lhs, const MazePosition &rhs) const;

    /**
     * @brief Inserts the given maze card in this maze at the given position.
     *
     * The position must be the one of a movable maze card and bust be different
     * than the position of last inserted card.
     *
     * @param mazeCard is the maze card to insert in this maze.
     * @param position is the position of the maze card to insert.
     * @return the maze card that has been pushed out.
     */
    MazeCard insertAt(const MazeCard &mazeCard, const MazePosition &position);

    /**
     * @brief Tells if a maze card can be inserted at the given position.
     * @return true if a maze card can be inserted at the given position.
     */
    bool isInserrable(MazePosition position) const;

    // TODO: méthodes qui permet de trouver un chemin à partir d'une position
    // La méthode retourne la liste des chemins possible en partant d'une postion
    // La classe path contient une liste de positions. Elle a une méthode qui permet
    // de savoir si une position donnée est sur son chemin
    // std::vector<MazePath> getPossiblePaths(MazePosition start);

};

}

#endif // MAZE_H

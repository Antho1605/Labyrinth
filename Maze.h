#ifndef MAZE_H
#define MAZE_H

#include "MazePosition.h"
#include "MazeCard.h"

namespace labyrinth {

/**
 * @brief Represents the maze of the game.
 */
struct Maze
{

    /**
     * @brief Is this maze size.
     */
    static const unsigned SIZE;

private:
    /**
     * @brief Is the last maze card that has been inserted in this maze. It is
     * not possible to insert aa new maze card at its position.
     */
    MazeCard lastMazeCardInserted_;

    /**
     * @brief Is the adjacency matrice of this maze.
     */
    bool *adjacencyMatrice_;

public:

    Maze() = default;

    /**
     * @brief Gets the last card inserted in this maze.
     *
     * @return the last card inserted in this maze.
     */
    MazeCard getLastMazeCardInserted() const { return lastMazeCardInserted_; }

    /**
     * @brief Updates the adjacency matrice of this maze.
     */
    void updateAdjacencyMatrice();

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
    MazeCard insertAt(const MazeCard &mazeCard, MazePosition position);

};

}

#endif // MAZE_H

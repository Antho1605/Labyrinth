#ifndef MAZE_H
#define MAZE_H

#include <map>

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
     * @brief Represents our graph. It allows us to represent this maze.
     */
    typedef std::map<MazeCard, std::vector<MazeCard>> Graph;
    Graph mazeCards;

public:

    Maze() = default;

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

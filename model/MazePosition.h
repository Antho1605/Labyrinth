#ifndef POSITION_H
#define POSITION_H

#include "mazedirection.h"

namespace labyrinth {

/**
 * @brief Represents a position in the maze.
 */
class MazePosition
{

    unsigned row_;
    unsigned column_;

public:

    /**
     * @brief Constructs a possible position in the maze of the game.
     *
     * @param row is the row of this position.
     * @param column is the column of this position.
     */
    MazePosition(unsigned row, unsigned column);

    /**
     * @brief Constructs this a position to the top left.
     */
    MazePosition()
        : row_{0}, column_{0}
    {}

    /**
     * @brief Gets this position row.
     *
     * @return this position row.
     */
    unsigned getRow() const { return row_; }

    /**
     * @brief Gets this position row.
     *
     * @return this position row.
     */
    unsigned getColumn() const { return column_; }

    /**
     * @brief Moves this position to the given coordinates.
     *
     * @param row is the row of this position.
     * @param column is the column of this position.
     */
    void moveTo(unsigned row, unsigned column);

    MazeDirection getDirectionTo(const MazePosition &destination) const;


};

}
#endif // POSITION_H

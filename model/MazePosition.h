#ifndef POSITION_H
#define POSITION_H

#include "MazeDirection.h"

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

    /**
     * @brief Gets the direction to the given position.
     *
     * For instance, the current position (0; 0) and (0; 1) is given. The
     * direction is right because (0; 1) is on the right of (0; 0).
     *
     * The given position should be a direct neighbor. A direct neighbor is right
     * next to this position.
     *
     * The given position should be different than this one.
     *
     * @param neighbor is the neighbor to get the direction to.
     * @return the direction to neighbor.
     * @throws logic_error if the given position is not valid.
     */
    MazeDirection getDirectionTo(const MazePosition &neighbor) const;

    /**
     * @brief Tells if this position has a neighbor in the given direction.
     *
     * @param direction is the direction of the neighbor.
     * @return true if this position has a neighbor in the given position.
     */
    bool hasNeighbor(const MazeDirection &direction) const;

    /**
     * @brief Gets this position neighbor.
     *
     * @param direction is the direction where to get the neighbor from.
     * @return the neighbor of this position.
     */
    MazePosition getNeighbor(const MazeDirection &direction) const;

};

inline bool operator<(const MazePosition &lhs, const MazePosition &rhs) {
    return lhs.getRow() < rhs.getRow() && lhs.getColumn() < rhs.getColumn();
}

inline bool operator==(const MazePosition &lhs, const MazePosition &rhs) {
    return lhs.getRow() == rhs.getRow() && lhs.getColumn() == rhs.getColumn();
}

}
#endif // POSITION_H

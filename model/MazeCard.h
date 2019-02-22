#ifndef MAZECARD_H
#define MAZECARD_H

namespace labyrinth {

/**
 * @brief Represents a maze card. A maze card is card representing one of the
 * pathways of the maze.
 */
struct MazeCard
{

    /**
     * @brief Represents the shape of a maze card.
     */
    struct Shape
    {
        bool up;
        bool right;
        bool bottom;
        bool left;
    };

protected:

    /**
     * @brief Is the shape of this maze card.
     */
    Shape shape_;

    /**
     * @brief Tells if this maze card is movable or not.
     */
    bool isMovable_;

public:

    /**
     * @brief Constructs this maze card.
     *
     * @param shape is the shape of this maze card.
     * @param isMovable is true if this maze card can be moved.
     */
    MazeCard(const Shape &shape, bool isMovable);

    /**
     * @brief Tells if this maze card is movable.
     *
     * @return true if this maze card is movable.
     */
    bool isMovable() const { return isMovable_; }

    /**
     * @brief Tells if this maze card is going up.
     *
     * @return true if this maze card is going up.
     */
    bool isGoingUp() const { return shape_.up; }

    /**
     * @brief Tells if this maze card is going right.
     *
     * @return true if this maze card is going right.
     */
    bool isGoingRight() const { return shape_.right; }

    /**
     * @brief Tells if this maze card is going down.
     *
     * @return true if this maze card is going down.
     */
    bool isGoingDown() const { return shape_.bottom; }

    /**
     * @brief Tells if this maze card is going left.
     *
     * @return true if this maze card is going left.
     */
    bool isGoingLeft() const { return shape_.left; }

    /**
     * @brief Rotates this maze card.
     */
    void rotate();

};

}

#endif // MAZECARD_H

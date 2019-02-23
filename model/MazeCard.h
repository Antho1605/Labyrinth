#ifndef MAZECARD_H
#define MAZECARD_H

#include "MazeCardShape.h"

namespace labyrinth {

/**
 * @brief Represents a maze card. A maze card is card representing one of the
 * pathways of the maze.
 */
class MazeCard
{

protected:

    /**
     * @brief Describes the informations relative to this class instances.
     */
    static struct InstancesRestriction {
        unsigned MAX_NB_OF_MOVABLE_CARDS;
        unsigned TOTAL_NB_OF_MOVABLE_CARDS;
        unsigned MAX_NB_OF_STEADY_CARDS;
        unsigned TOTAL_NB_OF_STEADY_CARDS;
    } T_RESTRICTION, L_RESTRICTION, I_RESTRICTION;

    /**
     * @brief Is the shape of this maze card.
     */
    MazeCardShape shape_;

    /**
     * @brief Tells if this maze card is movable or not.
     */
    bool isMovable_;

    void update(InstancesRestriction &, bool);

    void requireValidNbOfCards(InstancesRestriction &) const;

public:

    /**
     * @brief Constructs this maze card.
     *
     * @param shape is the shape of this maze card.
     * @param isMovable is true if this maze card can be moved.
     */
    MazeCard(const MazeCardShape &shape, bool isMovable=true);

    /**
     * @brief Tells if this maze card is movable.
     *
     * @return true if this maze card is movable.
     */
    bool isMovable() const { return isMovable_; }

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isT() const;

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isL() const;

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isI() const;

    /**
     * @brief Tells if this maze card is going up.
     *
     * @return true if this maze card is going up.
     */
    bool isGoingUp() const { return shape_.isGoingUp(); }

    /**
     * @brief Tells if this maze card is going right.
     *
     * @return true if this maze card is going right.
     */
    bool isGoingRight() const { return shape_.isGoingRight(); }

    /**
     * @brief Tells if this maze card is going down.
     *
     * @return true if this maze card is going down.
     */
    bool isGoingDown() const { return shape_.isGoingDown(); }

    /**
     * @brief Tells if this maze card is going left.
     *
     * @return true if this maze card is going left.
     */
    bool isGoingLeft() const { return shape_.isGoingLeft(); }

    /**
     * @brief Rotates this maze card.
     */
    void rotate() { shape_.rotate(); }

};

}

#endif // MAZECARD_H

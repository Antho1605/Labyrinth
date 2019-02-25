#ifndef MAZECARDL_H
#define MAZECARDL_H

#include <stdexcept>
#include "MazeCard.h"
#include "Object.h"

namespace labyrinth {

/**
 * @brief Represents a marked maze card. It is a maze card that is marked with
 * an object.
 */
class MarkedMazeCard : MazeCard
{
    /**
     * @brief Is the object marked on this maze card.
     */
    Object object_;

public:

    /**
     * @brief Constructs this card.
     *
     * @param shape is the shape of this maze card.
     * @param isMovable is true if this card is movable.
     * @param object is the object marked on this card.
     */
    MarkedMazeCard(const MazeCardShape &shape, bool isMovable, const Object &object)
        : MazeCard{shape, isMovable}, object_{object}
    {}

    /**
     * @brief Gets this card object.
     *
     * @return this card object.
     */
    Object getObject() { return object_; }

};

}

#endif // MAZECARDL_H

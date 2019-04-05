#ifndef OBJECTCARD_H
#define OBJECTCARD_H
#include "Object.h"

namespace labyrinth { namespace model {

/**
 * @brief Represents an object card.
 */
struct ObjectCard
{

private:

    /**
     * @brief Is the object of this object card.
     */
    Object object_;

    /**
     * @brief Tells if this card is turned over. An object card is turned over
     * when its owner fount this object in the maze.
     */
    bool isTurnedOver_;

public:

    /**
     * @brief Constructs this object card. Initially, this card is not turned over.
     *
     * @param object is the object of this card.
     */
    ObjectCard(Object object)
        : object_{object}, isTurnedOver_{false}
    {}

    /**
     * @brief Gets this object card.
     *
     * @return this object card.
     */
    Object getObject() const { return object_; }

    /**
     * @brief Tells if this card is turned over.
     *
     * @return true if this card is turned over.
     */
    bool isTurnedOver() const { return isTurnedOver_; }

    /**
     * @brief Turn this card over.
     */
    void turnOver() { isTurnedOver_ = true; }

};

}}

#endif // OBJECTCARD_H

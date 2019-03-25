#ifndef MAZECARDSHAPE_H
#define MAZECARDSHAPE_H

#include "MazeDirection.h"

namespace labyrinth {

/**
 * @brief @brief Represents the shape of a maze card.
 *
 * More informations on implementation choice here:
 * https://stackoverflow.com/questions/21295935/can-a-c-enum-class-have-methods
 */
class MazeCardShape
{

public:

    static const unsigned MAX_VALUE{0b1110};
    static const unsigned MIN_VALUE{0b0001};

    /**
     * @brief Constructs this maze card shape.
     *
     * @param value is an unsigned between 1 and 14.
     */
    MazeCardShape(const unsigned value);

    /**
     * @brief Constructs a shape that has no diretions.
     */
    MazeCardShape()
    : value_{static_cast<MazeDirection>(0)}
    {}

    /**
     * @brief getValue gets the shape of the MazeCardShape.
     * @return the shape.
     */
    MazeDirection getValue(){return value_;}

    /**
     * @brief Tells if this maze card shape is going to the given direction.
     *
     * @param direction is the direction this shape is going to.
     * @return true if this shape is going to the given position.
     */
    bool isGoing(const MazeDirection direction) const {
        return value_ & direction;
    }

    /**
     * @brief Tells if this card is a L.
     *
     * @return true if this card is a L.
     */
    bool isL() const;

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isT() const;

    /**
     * @brief Tells if this card is an I.
     *
     * @return true if this card is an I.
     */
    bool isI() const;

    /**
     * @brief Rotates this maze card shape.
     */
    void rotate();

    bool operator==(const MazeCardShape &other) const;

    private:

    /**
     * @brief value_ is the value of this maze card shape.
     */
    MazeDirection value_;
};

}
#endif // MAZECARDSHAPE_H

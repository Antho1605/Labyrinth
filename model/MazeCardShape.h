#ifndef MAZECARDSHAPE_H
#define MAZECARDSHAPE_H

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

   /**
    * @brief Represents the flags of this maze card shape.
    */
    enum Shape
    {
        UP = 1,
        RIGHT = 2,
        DOWN = 4,
        LEFT = 8
    };

    /**
     * @brief Constructs this maze card shape.
     *
     * @param value is an unsigned between 1 and 14.
     */
    MazeCardShape(const unsigned value);

    /**
     * @brief Tells if this maze card shape is going up.
     *
     * @return true if this maze card shape is going up.
     */
    bool isGoingUp() const
    {
        return value_ & Shape::UP;
    }

    /**
     * @brief Tells if this maze card shape is going up.
     *
     * @return true if this maze card shape is going up.
     */
    bool isGoingRight() const
    {
        return value_ & Shape::RIGHT;
    }

    /**
     * @brief Tells if this maze card shape is going up.
     *
     * @return true if this maze card shape is going up.
     */
    bool isGoingDown() const
    {
        return value_ & Shape::DOWN;
    }

    /**
     * @brief Tells if this maze card shape is going up.
     *
     * @return true if this maze card shape is going up.
     */
    bool isGoingLeft() const
    {
        return value_ & Shape::LEFT;
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

private:

    /**
     * @brief value_ is the value of this maze card shape.
     */
    Shape value_;

};

}
#endif // MAZECARDSHAPE_H

#include <bitset>
#include <sstream>
#include <stdexcept>
#include "MazeCardShape.h"

namespace labyrinth {

static MazeCardShape::Shape requireValidValue(unsigned value)
{
    std::stringstream errmsg;
    errmsg << value << " is not a valid value, the shape cannot be constructed";
    if (value < 1 || 0b1110 < value) {
        throw std::invalid_argument(errmsg.str());
    }
    return static_cast<MazeCardShape::Shape>(value);
}

MazeCardShape::MazeCardShape(const unsigned value)
    : value_{requireValidValue(value)}
{}

bool MazeCardShape::isT() const
{
    std::bitset<4> shape_memory = value_;
    return shape_memory.count() == 3;
}

bool MazeCardShape::isI() const
{
    return value_ == static_cast<Shape>(Shape::UP | Shape::DOWN)
            || value_ == static_cast<Shape>(Shape::LEFT | Shape::RIGHT);
}

bool MazeCardShape::isL() const
{
    std::bitset<4> shape_memory = value_;
    return shape_memory.count() == 2 && !isI();
}

/**
 * @brief Makes a circular shift to the left of the given bitset.
 *
 * For instance,
 * - the bitset 0b1000 becomes 0b0001
 * - the bitset 0b1101 becomes 0b1011
 * - the bitset 0b0011 becomes 0b0110
 *
 * You can find more information on the circular shift at:
 * https://en.wikipedia.org/wiki/Circular_shift
 *
 * @param bitset is the bitset to shift.
 * @param shift is the lenght of the shift.
 * @return the shifted bitsed.
 */
static int circularLeftShift(int bitset, unsigned int shift)
{
    return (bitset << shift) | (bitset >> (4 - shift));
}

void MazeCardShape::rotate()
{
    value_ = static_cast<Shape>(circularLeftShift(value_, 1));
}

}

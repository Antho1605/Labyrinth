#include <bitset>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "MazeCardShape.h"

namespace labyrinth { namespace model {

static bool valueInBounds(unsigned value){
    return value < MazeCardShape::MIN_VALUE || MazeCardShape::MAX_VALUE < value;
}

static MazeDirection requireValidValue(unsigned value)
{
    std::stringstream errmsg;
    errmsg << value << " is not a valid value, the shape cannot be constructed";
    if (valueInBounds(value)) {
        throw std::invalid_argument(errmsg.str());
    }
    return static_cast<MazeDirection>(value);
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
    std::bitset<4> shape_memory = value_;
    return shape_memory ==
            static_cast<MazeDirection>(MazeDirection::DOWN | MazeDirection::UP)
            || shape_memory ==
            static_cast<MazeDirection>(MazeDirection::LEFT | MazeDirection::RIGHT);
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
    value_ = static_cast<MazeDirection>(circularLeftShift(value_, 1));
    value_ = static_cast<MazeDirection>(value_ % 16); // we keep meaningful bits only
}

bool MazeCardShape::operator==(const MazeCardShape &other) const{
    return this->value_ == other.value_;
}

}}

#include <stdexcept>
#include <bitset>

#include "MazeCard.h"

namespace labyrinth {

MazeCard::InstancesRestriction MazeCard::T_restriction{6, 0, 12, 0};
MazeCard::InstancesRestriction MazeCard::L_restriction{16, 0, 4, 0};
MazeCard::InstancesRestriction MazeCard::I_restriction{12, 0, 0, 0};

static int circularLeftShift(int bitset, unsigned int shift)
{
    return (bitset << shift) | (bitset >> (4 - shift));
}

static bool isValidShape(const MazeCard::Shape &shape)
{
    // TODO
}

static void requireValidShape(const MazeCard::Shape & shape)
{
    // TODO
}

MazeCard::MazeCard(const MazeCard::Shape &shape, bool isMovable)
    : shape_{shape}, isMovable_{isMovable}
{}

bool MazeCard::isT() const
{
    std::bitset<4> shape = shape_;
    return shape.count() == 3;
}

bool MazeCard::isL() const
{
    std::bitset<4> shape = shape_;
    return shape.count() == 2 && !isI();
}

bool MazeCard::isI() const
{
    return (isGoingDown() && isGoingUp()) || (isGoingRight() && isGoingLeft());
}

void MazeCard::rotate()
{
    shape_ = static_cast<Shape>(circularLeftShift(shape_, 1));
}

}

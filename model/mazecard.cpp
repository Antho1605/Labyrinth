#include "MazeCard.h"

using namespace labyrinth;


bool MazeCard::hasSameType(const MazeCard &other) const{
    return (other.isI() && this->isI()) || (other.isT() && this->isT())
                    || (other.isL() && this->isL());
}

bool MazeCard::isEqualTo(const MazeCard &other) const{
    return hasSameType(other) && hasSameMoving(other)
            && hasSameShape(other);
}

bool MazeCard::operator==(const MazeCard other) const{
    return isEqualTo(other);
}

bool MazeCard::hasSameShape(const MazeCard &other) const{
    return other.shape_ == this->shape_;
}

bool MazeCard::hasSameMoving(const MazeCard &other) const{
    return ((other.isMovable() && this->isMovable()) ||
            (!other.isMovable() && !this->isMovable()));
}

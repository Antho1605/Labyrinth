#ifndef MAZEDIRECTION_H
#define MAZEDIRECTION_H

namespace labyrinth { namespace model {

/**
 * @brief Represents the flags of this maze card shape.
 */
enum MazeDirection
{
    UP = 1,
    RIGHT = 2,
    DOWN = 4,
    LEFT = 8
};

inline MazeDirection &operator++(MazeDirection &direction) {
    direction = static_cast<MazeDirection>(direction * 2);
    return direction;
}

}}

#endif // MAZEDIRECTION_H

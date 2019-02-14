#ifndef MAZECARDT_H
#define MAZECARDT_H

#include <stdexcept>
#include "mazecard.h"

namespace labyrinth {

class MazeCardT : MazeCard
{
    static unsigned MAX_NB_OF_INSTANCES;
    static unsigned NB_OF_INSTANCES;
public:
    MazeCardT(Object *object, bool isMovable)
        : MazeCard{object, isMovable}
    {
        if (NB_OF_INSTANCES > MAX_NB_OF_INSTANCES) {
            throw std::logic_error("The maximum possible number of instances is reached.");
        }
    }
};

}

#endif // MAZECARDT_H

#ifndef MAZECARDI_H
#define MAZECARDI_H

#include <stdexcept>
#include "mazecard.h"

namespace labyrinth {

class MazeCardI : public MazeCard
{
    static unsigned MAX_NB_OF_INSTANCES;
    static unsigned NB_OF_INSTANCES;
public:
    MazeCardI()
        : MazeCard{nullptr, true}
    {
        if (NB_OF_INSTANCES > MAX_NB_OF_INSTANCES) {
            throw std::logic_error("The maximum possible number of instances is reached.");
        }
    }
};

}
#endif // MAZECARDI_H

#ifndef MAZECARD_H
#define MAZECARD_H
#include "object.h"

namespace labyrinth {

class MazeCard
{
protected:
    Object object_;
    bool isMovable;
public:
    MazeCard(Object object, bool isMovable);
};

}

#endif // MAZECARD_H

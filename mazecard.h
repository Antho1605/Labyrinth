#ifndef MAZECARD_H
#define MAZECARD_H
#include "object.h"

namespace labyrinth {

class MazeCard
{
protected:
    Object *object_;
    bool isMovable_;
public:
    MazeCard(Object *object, bool isMovable);
    Object *getObject() const {return object_;}
    bool isMovable() const {return isMovable_;}
    void rotate();
};

}

#endif // MAZECARD_H

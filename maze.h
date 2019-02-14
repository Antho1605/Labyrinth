#ifndef MAZE_H
#define MAZE_H

#include "mazecard.h"

namespace labyrinth {

class Maze
{
    MazeCard *lastMazeCardAdded;
public:
    Maze() = default;
    MazeCard *getLastMazeCard() const;
};

}

#endif // MAZE_H

#ifndef NODE_H
#define NODE_H
#include "mazecard.h"
#include <vector>

struct Node{
    MazeCard mazeCard_;
    std::vector<MazeCard> neighbour_;
};

#endif // NODE_H

#ifndef GAME_H
#define GAME_H
#include <vector>
#include "mazecard.h"

class Game{
    std::vector<MazeCard> deck_;
    MazeCard currentMazeCard_;
    public:
    Game(){
        initMazeCards();
    }
    void initMazeCards();
};

#endif // GAME_H

#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"

class Player{
    Color color_;
    unsigned age_;
    public:
    Player(Color color, unsigned age) : color_{color} , age_{age}
    {
    }
    Color getColor_();
    unsigned getAge_();
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"
#include "position.h"
#include "objectcard.h"
#include <vector>

namespace labyrinth {

enum class PlayerState
{
    WAITING,
    MOVING_PATHWAYS,
    MOVING_PIECE,
    PASS
};

class Player{
    Color color_;
    unsigned age_;
    Position position_;
    PlayerState state_;
    std::vector<ObjectCard> objectives_;
public:
    Player(Color color, unsigned age, Position position)
        : color_{color},
          age_{age},
          position_{position}, state_{PlayerState::WAITING} {}
    Color getColor_();
    unsigned getAge_();
    Position getPosition();
};

}

#endif // PLAYER_H

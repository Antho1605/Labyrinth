#include "Player.h"
#include <stdexcept>

namespace labyrinth{

void Player::nextObjective(){
    if (currentObjective_ != nullptr) {
        currentObjective_->turnOver();
    }
    currentObjective_ = objectives_.getCurrentCard();
}

}

#include "Player.h"
#include <stdexcept>

namespace labyrinth{
/**
     * @brief Turn over the current objective and sets the player current objective to the next one.
     */
void Player::nextObjective(){
    if(hasFoundAllObjectives()){
        currentObjective_ = nullptr;
    }else{
        if(currentObjective_ != nullptr){
            currentObjective_->turnOver();
        }
        currentObjective_ = objectives_.nextCard();
    }
}
}

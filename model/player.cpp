#include "Player.h"

namespace labyrinth{
    /**
     * @brief Turn over the current objective and sets the player current objective to the next one.
     */
    void Player::nextObjective()
    {
        if(currentObjective_ != nullptr){
            currentObjective_->turnOver();
        }
        currentObjective_ = getNextCard();
    }

    ObjectCard * Player::getNextCard(){
            for(unsigned i{0}; i<objectives_.size();++i){
                if(!objectives_.at(i).isTurnedOver()){
                    return &objectives_.at(i);
                }
            }
            return &objectives_.at(0);
    }
}

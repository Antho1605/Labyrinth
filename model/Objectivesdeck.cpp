#include "Objectivesdeck.h"
#include "ObjectCard.h"

bool ObjectivesDeck::allObjectivesFound(){
    for(unsigned i{0}; i<deck_.size();++i){
        if(!deck_.at(i).isTurnedOver()){
            return false;
        }
    }
    return true;
}

labyrinth::ObjectCard * ObjectivesDeck::getCurrentCard(){
    for(unsigned i{0}; i<deck_.size();++i){
        if(!deck_.at(i).isTurnedOver()){
            return &deck_.at(i);
        }
    }
    return nullptr;
}

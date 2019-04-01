#include <stdexcept>
#include <sstream>

#include "ObjectivesDeck.h"
#include "ObjectCard.h"

using namespace std;

namespace labyrinth {

template<typename Container>
static bool isValidSize(const Container &objectives) {
    return objectives.size() == 6 ||
            objectives.size() == 8 ||
            objectives.size() == 12;
}

template<typename Container>
static Container requireValidSize(const Container &objectives)
{
    stringstream ss;
    ss << "Invalid number of objectives! You are trying to construct an ";
    ss << "objectives deck with " << objectives.size() << " objectives but";
    ss << " there should either be 6, 8, or 12 of them.\n";
    if (!isValidSize(objectives)) {
        throw std::invalid_argument(ss.str());
    }
    return objectives;
}

ObjectivesDeck::ObjectivesDeck(const vector<ObjectCard> &objectives)
    : cards_{requireValidSize(objectives)}
{}

ObjectivesDeck::ObjectivesDeck(const initializer_list<ObjectCard> &objectives)
    : cards_{requireValidSize(objectives)}
{}

bool ObjectivesDeck::areAllCardsTurnedOver() const {
    for(unsigned i{0}; i<cards_.size();++i){
        if(!cards_.at(i).isTurnedOver()){
            return false;
        }
    }
    return true;
}

labyrinth::ObjectCard &ObjectivesDeck::getCurrentCard(){
    for(unsigned card{0}; card<cards_.size();++card){
        if(!cards_.at(card).isTurnedOver()){
            return cards_.at(card);
        }
    }
    throw std::logic_error("No object card to get anymore.");
}

}

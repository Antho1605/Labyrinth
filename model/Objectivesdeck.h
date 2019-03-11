#ifndef OBJECTIVESDECK_H
#define OBJECTIVESDECK_H
#include <vector>
#include <string>
#include <stdexcept>
#include "ObjectCard.h"

class ObjectivesDeck
{

    std::vector<labyrinth::ObjectCard> deck_;

public:

    ObjectivesDeck(std::vector<labyrinth::ObjectCard> objectives) :
    deck_{deckSizeValid(objectives) ? objectives :
    throw std::invalid_argument("Wrong size of deck : " + std::to_string(objectives.size()))}
    {}

    ObjectivesDeck(std::initializer_list<labyrinth::ObjectCard> objectives)
        : deck_{objectives}
    {}

    labyrinth::ObjectCard * getCurrentCard();

    std::vector<labyrinth::ObjectCard> getDeck() {return deck_;}

    bool deckSizeValid(std::vector<labyrinth::ObjectCard> objectives){
        return objectives.size() == 6 || objectives.size() == 8 || objectives.size() == 12;
    }

    bool allObjectivesFound();

    void addObjectiveCard(labyrinth::ObjectCard objectCard){deck_.push_back(objectCard);}

};
#endif // OBJECTIVESDECK_H

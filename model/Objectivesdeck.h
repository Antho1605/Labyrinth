#ifndef OBJECTIVESDECK_H
#define OBJECTIVESDECK_H
#include <vector>
#include <string>
#include <stdexcept>
#include "ObjectCard.h"

namespace labyrinth {

class ObjectivesDeck
{

    std::vector<ObjectCard> cards_;

public:

    /**
     * @brief Constructs this deck with the given vector of objects.
     *
     * @param objectives are the objectives contained in this deck.
     */
    ObjectivesDeck(const std::vector<ObjectCard> &objectives);


    /**
     * @brief Constructs this deck with the given list of objects.
     *
     * @param objectives are the objectives contained in this deck.
     */
    ObjectivesDeck(const std::initializer_list<ObjectCard> &objectives);

    /**
     * @brief Gets the current card of this deck. The current card is the one
     * on the top.
     *
     * @return the current card of this deck.
     */
    labyrinth::ObjectCard * getCurrentCard();

    /**
     * @brief Gets this deck cards.
     *
     * @return this deck cards.
     */
    std::vector<ObjectCard> getCards() {return cards_;}

    bool allObjectivesFound();

    void add(const ObjectCard &objectCard){
        cards_.push_back(objectCard);
    }

};

}
#endif // OBJECTIVESDECK_H

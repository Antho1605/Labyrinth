#ifndef OBJECTIVESDECK_H
#define OBJECTIVESDECK_H
#include <vector>
#include <string>
#include <stdexcept>
#include "ObjectCard.h"

namespace labyrinth { namespace model {

class ObjectivesDeck
{

    /**
     * @brief Are the cards of this deck.
     */
    std::vector<ObjectCard> cards_;

public:

    /**
     * @brief Constructs this deck with the given vector of objects.
     *
     * @param objectives are the objectives contained in this deck.
     */
    ObjectivesDeck(const std::vector<ObjectCard> &objectives);

    ObjectivesDeck() = default;

    ObjectivesDeck(const ObjectivesDeck &) = default;

    ObjectivesDeck(ObjectivesDeck &&) = default;

    /**
     * @brief Constructs this deck with the given list of objects.
     *
     * @param objectives are the objectives cotained in this deck.
     */
    ObjectivesDeck(const std::initializer_list<ObjectCard> &objectives);

    /**
     * @brief Gets the current card of this deck. The current card is the first
     * card that is not turned over.
     *
     *
     *
     * @return the current card of this deck. When all this deck cards are
     * turned over nullptr is returned.
     */
    labyrinth::model::ObjectCard &getCurrentCard();

    /**
     * @brief Gets this deck cards.
     *
     * @return this deck cards.
     */
    std::vector<ObjectCard> getCards() const { return cards_; }

    /**
     * @brief Tells if this deck card are all turned over.
     *
     * @return true if all this deck card are turned over.
     */
    bool areAllCardsTurnedOver() const;

    /**
     * @brief Turn all the cards of this deck over. This method is used for
     * unit testing.
     */
    void turnOverAllCards();

    ~ObjectivesDeck() = default;

    ObjectivesDeck& operator=(const ObjectivesDeck &that)
    {
        cards_ = that.cards_;
        return *this;
    }

};

}}
#endif // OBJECTIVESDECK_H

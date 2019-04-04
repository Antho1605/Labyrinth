#ifndef MAZECARDSBUILDER_H
#define MAZECARDSBUILDER_H

#include "MazeCard.h"
#include "Object.h"

#include <vector>

namespace labyrinth { namespace model {

/**
 * @brief Class used to constructs the game cards.
 */
struct MazeCardsBuilder
{

    static unsigned MARKED_T_CARDS;
    static unsigned I_CARDS;
    static unsigned L_CARDS;
    static unsigned MARKED_L_CARDS;

    MazeCardsBuilder() = default;

    /**
     * @brief Gets all the steady cards.
     *
     * @param cards is the vector containing the cards.
     */
    static void getSteadyCards(std::vector<MazeCard> &cards);

    /**
     * @brief Gets all the movable cards.
     *
     * @param cards is the vector containing the cards.
     */
    static void getMovableCards(std::vector<MazeCard> &cards);

    static void constructMarkedTCards(std::vector<MazeCard> &cards);

    static void constructICards(std::vector<MazeCard> &cards);

    static void constructLCards(std::vector<MazeCard> &cards);

    static void constructMarkedLCards(std::vector<MazeCard> &cards);

private:

    static Object CURRENT_OBJECT;

};

}}

#endif // MAZECARDSBUILDER_H

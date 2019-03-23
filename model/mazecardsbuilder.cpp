#include "MazeCardsBuilder.h"
#include "MarkedMazeCard.h"

namespace labyrinth {

Object MazeCardsBuilder::CURRENT_OBJECT = Object::GHOST;
unsigned MazeCardsBuilder::MARKED_T_CARDS = 6;
unsigned MazeCardsBuilder::I_CARDS = 12;
unsigned MazeCardsBuilder::L_CARDS = 10;
unsigned MazeCardsBuilder::MARKED_L_CARDS = 6;

void MazeCardsBuilder::getSteadyCards(std::vector<MazeCard> &steadyCards)
{
    steadyCards.push_back(MazeCard{RIGHT | DOWN, false});
    steadyCards.push_back(MazeCard{RIGHT | DOWN | LEFT, false});
    steadyCards.push_back(MazeCard{RIGHT | DOWN | LEFT, false});
    steadyCards.push_back(MazeCard{LEFT | DOWN, false});
    steadyCards.push_back(MazeCard{UP | DOWN | RIGHT, false});
    steadyCards.push_back(MazeCard{UP | DOWN | RIGHT, false});
    steadyCards.push_back(MazeCard{LEFT | DOWN | RIGHT, false});
    steadyCards.push_back(MazeCard{LEFT | UP | DOWN, false});
    steadyCards.push_back(MazeCard{UP | DOWN | RIGHT, false});
    steadyCards.push_back(MazeCard{LEFT | UP | RIGHT, false});
    steadyCards.push_back(MazeCard{LEFT | DOWN | UP, false});
    steadyCards.push_back(MazeCard{LEFT | DOWN | UP, false});
    steadyCards.push_back(MazeCard{RIGHT | UP, false});
    steadyCards.push_back(MazeCard{RIGHT | LEFT | UP, false});
    steadyCards.push_back(MazeCard{RIGHT | LEFT | UP, false});
    steadyCards.push_back(MazeCard{LEFT | UP, false});
}

void MazeCardsBuilder::constructICards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < I_CARDS; ++i) {
        cards.push_back(MazeCard{UP | DOWN});
        nextObject();
    }
}

void MazeCardsBuilder::constructLCards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < MARKED_L_CARDS; ++i) {
        cards.push_back(MazeCard{UP | RIGHT});
        nextObject();
    }
}

void MazeCardsBuilder::constructMarkedTCards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < MARKED_T_CARDS; ++i) {
        cards.push_back(MarkedMazeCard{UP | DOWN | RIGHT, CURRENT_OBJECT});
        nextObject();
    }
}

void MazeCardsBuilder::constructMarkedLCards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < MARKED_L_CARDS; ++i) {
        cards.push_back(MarkedMazeCard{UP | RIGHT, CURRENT_OBJECT});
        nextObject();
    }
}

void MazeCardsBuilder::getMovableCards(std::vector<MazeCard> &cards)
{
    constructICards(cards);
    constructLCards(cards);
    constructMarkedLCards(cards);
    constructMarkedTCards(cards);
}

}

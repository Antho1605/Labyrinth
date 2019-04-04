#include "MazeCardsBuilder.h"

#include <iostream>

namespace labyrinth { namespace model {

Object MazeCardsBuilder::CURRENT_OBJECT = Object::GHOST;
unsigned MazeCardsBuilder::MARKED_T_CARDS = 6;
unsigned MazeCardsBuilder::I_CARDS = 12;
unsigned MazeCardsBuilder::L_CARDS = 10;
unsigned MazeCardsBuilder::MARKED_L_CARDS = 6;



void MazeCardsBuilder::getSteadyCards(std::vector<MazeCard> &steadyCards)
{
    steadyCards.push_back(MazeCard{RIGHT | DOWN, false});
    steadyCards.push_back(MazeCard{RIGHT | DOWN | LEFT, false, GRIMOIRE});
    steadyCards.push_back(MazeCard{RIGHT | DOWN | LEFT, false, PURSE_OF_GOLD});
    steadyCards.push_back(MazeCard{LEFT | DOWN, false});
    steadyCards.push_back(MazeCard{UP | DOWN | RIGHT, false, MAP});
    steadyCards.push_back(MazeCard{UP | DOWN | RIGHT, false, CROWN});
    steadyCards.push_back(MazeCard{LEFT | DOWN | RIGHT, false, KEYS});
    steadyCards.push_back(MazeCard{LEFT | UP | DOWN, false, BONES});
    steadyCards.push_back(MazeCard{UP | DOWN | RIGHT, false, RING});
    steadyCards.push_back(MazeCard{LEFT | UP | RIGHT, false, TREASURE_CHEST});
    steadyCards.push_back(MazeCard{LEFT | DOWN | UP, false, EMERALD});
    steadyCards.push_back(MazeCard{LEFT | DOWN | UP, false, SWORD});
    steadyCards.push_back(MazeCard{RIGHT | UP, false});
    steadyCards.push_back(MazeCard{RIGHT | LEFT | UP, false, CHANDELIER});
    steadyCards.push_back(MazeCard{RIGHT | LEFT | UP, false, HELMET});
    steadyCards.push_back(MazeCard{LEFT | UP, false});
}

void MazeCardsBuilder::constructICards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < I_CARDS; ++i) {
        cards.push_back(MazeCard{UP | DOWN});
    }
}

void MazeCardsBuilder::constructLCards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < L_CARDS; ++i) {
        cards.push_back(MazeCard{UP | RIGHT});
    }
}

void MazeCardsBuilder::constructMarkedTCards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < MARKED_T_CARDS; ++i) {
        cards.push_back(MazeCard{UP | DOWN | RIGHT, true, CURRENT_OBJECT});
        ++CURRENT_OBJECT;
    }
}

void MazeCardsBuilder::constructMarkedLCards(std::vector<MazeCard> &cards) {
    for (unsigned i = 0; i < MARKED_L_CARDS; ++i) {
        cards.push_back(MazeCard{UP | RIGHT, true, CURRENT_OBJECT});
        ++CURRENT_OBJECT;
    }
}

void MazeCardsBuilder::getMovableCards(std::vector<MazeCard> &cards)
{
    constructICards(cards);
    constructLCards(cards);
    constructMarkedLCards(cards);
    constructMarkedTCards(cards);
}

}}

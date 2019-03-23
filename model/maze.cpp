#include "Maze.h"
#include <vector>

namespace labyrinth {

unsigned Maze::SIZE = 7;

MazeCard Maze::insertAt(const MazeCard &mazeCard, const MazePosition &position)
{
// TODO: est-ce une position movable?
//    MazeCard expulsed = cards_.at(position.getRow()).back();
//    cards_.at(position.getRow()).pop_back();
//    cards_.at(position.getRow()).push_front(mazeCard);
//    return expulsed;
}

void Maze::updateAdjacency()
{
    // TODO
}

static bool isSteadyCardPosition(unsigned row, unsigned column)
{
    return row % 2 == 0 && column % 2 == 0;
}

static void constructSteadyCards(std::vector<MazeCard> &steadyCards)
{

}

static void constructMovableCards(std::vector<MazeCard> &movableCards)
{

}

void Maze::initialize()
{
    std::vector<MazeCard> steadyCards;
    std::vector<MazeCard>::iterator steadyCardsIterator = steadyCards.begin();
    std::vector<MazeCard> movableCards;
    std::vector<MazeCard>::iterator movableCardsIterator = movableCards.begin();
    constructSteadyCards(steadyCards);
    constructMovableCards(movableCards);
    for (unsigned row = 0; row < SIZE; ++row) {
        for (unsigned column = 0; column < SIZE; ++column) {
            if (isSteadyCardPosition(row, column)) {
                cards_.at(row).push_back(*steadyCardsIterator);
                steadyCardsIterator++;
            } else {
                cards_.at(row).push_back(*movableCardsIterator);
                movableCardsIterator++;
            }
        }
    }
}

}

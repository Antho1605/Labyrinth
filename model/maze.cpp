#include "Maze.h"
#include "MazeDirection.h"

#include <vector>
#include <stdexcept>

using namespace labyrinth;

unsigned Maze::SIZE = 7;

MazeCard Maze::insertAt(const MazeCard &mazeCard, const MazePosition &position)
{
    if(isOutOfBounds(position))
        throw std::invalid_argument("The position is out of board");
    if(!canBeMoved(position))
        throw std::logic_error("This card is steady. She can't be moved");

    MazeCard expulsed_card{};
    if (position.getRow() == 0) {
        insertUp(mazeCard, expulsed_card);
    } else if (position.getRow() == cards_.size()) {
        insertDown(mazeCard, expulsed_card);
    } else if (position.getColumn() == 0) {
        insertLeft(mazeCard, expulsed_card, position);
    }else{
        insertRight(mazeCard, expulsed_card,position);
    }

    lastMazeCardInserted_ = mazeCard;
    return expulsed_card;
}

bool Maze::isOutOfBounds(const MazePosition &position)
{
    return position.getColumn()<0 && position.getColumn() > cards_.size() &&
            position.getRow() < 0 && position.getRow() > cards_.size();
}

bool Maze::areAdjacent(const MazePosition &lhs, const MazePosition &rhs) const
{
    MazeCard lhs_card = getCardAt(lhs);
    MazeCard rhs_card = getCardAt(rhs);
    return lhs_card.isGoing(lhs.getDirectionTo(rhs))
            && rhs_card.isGoing(rhs.getDirectionTo(lhs));
}

static MazePosition getNeighbor(const MazePosition& pos, int dir)
{
    unsigned row = pos.getRow();
    unsigned column = pos.getColumn();
    switch(dir)
    {
    case 1:
        ++row;
        break;
    case 2:
        ++column;
        break;
    case 3:
        --row;
        break;
    case 4:
        --column;
        break;
    }
    return MazePosition{row, column};
}

void Maze::updateAdjacency()
{
    for (auto &adjacency : adjacencies_) {
        MazePosition position = adjacency.first;
        std::vector<MazePosition> neighbors = adjacency.second;
        neighbors.clear();
        for (int direction = 0; direction < 4; ++direction) {
            MazePosition neighbor = getNeighbor(position, direction);
            //si estValide(direction) ET sontVoisins(position, voisin) alors
            if (areAdjacent(position, neighbor)) {
                neighbors.push_back(neighbor);
            }
        }
    }

}

static bool isSteadyCardPosition(unsigned row, unsigned column)
{
    return row % 2 == 0 && column % 2 == 0;
}

static void constructSteadyCards(std::vector<MazeCard> &steadyCards)
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

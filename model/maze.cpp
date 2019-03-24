#include "Maze.h"
#include "MazeDirection.h"
#include "mazecardsbuilder.h"

#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace labyrinth;

MazeCard Maze::insertAt(const MazeCard &mazeCard, const MazePosition &position)
{

}

bool Maze::isOutOfBounds(const MazePosition &position)
{
    return position.getColumn() > SIZE && position.getRow() > SIZE;
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
            if (!isOutOfBounds(neighbor) && areAdjacent(position, neighbor)) {
                neighbors.push_back(neighbor);
            }
        }
    }
}

static bool isSteadyCardPosition(unsigned row, unsigned column)
{
    return row % 2 == 0 && column % 2 == 0;
}

static int getRandomRotation() {
    return rand() % 4;
}

static void randomlyRotate(std::vector<MazeCard> &movableCards) {
    for (auto card : movableCards) {
        for (int rotation = 0; rotation < getRandomRotation(); ++rotation) {
            card.rotate();
        }
    }
}

static void buildCards(std::vector<MazeCard> &steady, std::vector<MazeCard> &movable)
{
    MazeCardsBuilder builder;
    builder.getSteadyCards(steady);
    builder.getMovableCards(movable);
    std::random_shuffle(movable.begin(), movable.end());
    randomlyRotate(movable);
}

void Maze::initialize()
{
    std::vector<MazeCard> steadyCards;
    std::vector<MazeCard> movableCards;
    unsigned currentSteady = 0;
    unsigned currentMovable = 0;
    buildCards(steadyCards, movableCards);
    for (unsigned row = 0; row < SIZE; ++row) {
        for (unsigned column = 0; column < SIZE; ++column) {
            if (isSteadyCardPosition(row, column)) {
                cards_[row][column] = steadyCards.at(currentSteady);
                currentSteady++;
            } else {
                cards_[row][column] = movableCards.at(currentMovable);
                currentMovable++;
            }
        }
    }
    updateAdjacency();
}

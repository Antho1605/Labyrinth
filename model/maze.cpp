#include "Maze.h"
#include "MazeDirection.h"
#include "mazecardsbuilder.h"

#include <vector>
#include <stdexcept>

using namespace labyrinth;

MazeCard Maze::insertAt(const MazeCard &mazeCard, const MazePosition &position)
{
    if(!isOnSide(position)){
        throw std::invalid_argument("The position is not on the maze's side.");
    }
    if(!cards_[position.getRow()][position.getColumn()].isMovable()){
        throw std::logic_error("This card is not movable");
    }
    MazeCard ejected_card{};
    if(isInsertingUp(position)){
        insertUpSide(ejected_card, position);
    }else if(isInsertingDown(position)){
        insertDownSide(ejected_card, position);
    }else if(isInsertingLeft(position)){
        insertLeftSide(ejected_card, position);
    }else{
        insertRightSide(ejected_card, position);
    }
    cards_[position.getRow()][position.getColumn()] = mazeCard;
    lastMazeCardInserted_ = mazeCard;
    return ejected_card;
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

void Maze::initialize()
{
    std::vector<MazeCard> steadyCards;
    std::vector<MazeCard>::iterator steadyCardsIterator = steadyCards.begin();
    std::vector<MazeCard> movableCards;
    std::vector<MazeCard>::iterator movableCardsIterator = movableCards.begin();
    MazeCardsBuilder builder;
    builder.getSteadyCards(steadyCards);
    builder.getMovableCards(movableCards);
    for (unsigned row = 0; row < SIZE; ++row) {
        for (unsigned column = 0; column < SIZE; ++column) {
            if (isSteadyCardPosition(row, column)) {
                cards_[row][column] = *steadyCardsIterator;
                steadyCardsIterator++;
            } else {
                cards_[row][column] = *movableCardsIterator;
                movableCardsIterator++;
            }
        }
    }
}

void Maze::insertUpSide(MazeCard &ejected_card, const MazePosition &position){
    ejected_card = cards_[SIZE-1][position.getColumn()];
    for(unsigned i{SIZE-1}; 0<=i; --i){
        cards_[i][position.getColumn()] = cards_[i-1][position.getColumn()];
    }
}

void Maze::insertDownSide(MazeCard &ejected_card, const MazePosition &position){
    ejected_card = cards_[0][position.getColumn()];
    for(unsigned i{0}; i<SIZE; ++i){
        cards_[i][position.getColumn()] = cards_[i+1][position.getRow()];
    }
}

void Maze::insertLeftSide(MazeCard &ejected_card, const MazePosition &position){
    ejected_card = cards_[position.getRow()][SIZE-1];
    for(unsigned i{SIZE-1}; 0<=i; --i){
        cards_[position.getRow()][i] = cards_[position.getRow()][i-1];
    }
}

void Maze::insertRightSide(MazeCard &ejected_card, const MazePosition &position){
    ejected_card = cards_[position.getRow()][0];
    for(unsigned i{0}; i<SIZE; ++i){
        cards_[position.getRow()][i] = cards_[position.getRow()][i+1];
    }
}








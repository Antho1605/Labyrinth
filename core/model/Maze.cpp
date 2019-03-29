#include "Maze.h"
#include "MazeDirection.h"
#include "MazeCardsBuilder.h"


#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;
using namespace labyrinth;

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

void Maze::initializeCards()
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
    lastPushedOutMazeCard_ = movableCards.at(currentMovable);
}

void Maze::initializeAdjacency()
{
    for (unsigned row = 0; row < SIZE; ++row) {
        for (unsigned column = 0; column < SIZE; ++column) {
            auto adj{make_pair(MazePosition{row, column}, vector<MazePosition>())};
            adjacencies_.insert(adj);
        }
    }
}

void Maze::initialize() {
    initializeAdjacency();
    initializeCards();
    updateAdjacency();
}

bool Maze::existPathBetween(const MazePosition &lhs, const MazePosition &rhs) const
{
    MazeCard lhs_card = getCardAt(lhs);
    MazeCard rhs_card = getCardAt(rhs);
    return lhs_card.isGoing(lhs.getDirectionTo(rhs))
            && rhs_card.isGoing(rhs.getDirectionTo(lhs));
}

void Maze::updateAdjacency()
{
    for (auto &adjacency : adjacencies_) {
        MazePosition position = adjacency.first;
        std::vector<MazePosition> &neighbors = adjacency.second;
        neighbors.clear();
        for (MazeDirection dir = UP; dir <= LEFT; ++dir) {
            if (position.hasNeighbor(dir)) {
                MazePosition neighbor = position.getNeighbor(dir);
                if (existPathBetween(position, neighbor)) {
                    neighbors.push_back(neighbor);
                }
            }
        }
    }
}

bool Maze::areAdjacent(const MazePosition &lhs, const MazePosition &rhs) const
{
    auto it = adjacencies_.find(lhs);
    if (it != adjacencies_.end()) {
        std::vector<MazePosition> adjacents = it->second;
        return std::find(adjacents.begin(), adjacents.end(), rhs) != adjacents.end();
    } else {
        throw std::invalid_argument("lhs has not been found.\n");
    }
}

bool Maze::isOnSide(const MazePosition &pos, const MazeDirection direction) const
{
    switch (direction)
    {
    case UP:
        return pos.getRow() == 0;
    case RIGHT:
        return pos.getColumn() == SIZE - 1;
    case DOWN:
        return pos.getRow() == SIZE - 1;
    case LEFT:
        return pos.getColumn() == 0;
    }
}

void Maze::requireInserrable(const MazePosition &position) const
{
    if(!getCardAt(position).isMovable()){
        throw std::logic_error("This is not allowed to insert at the given position!");
    }
    if (position == lastPushedOutPosition_) {
        throw std::logic_error("Trying to push the maze card at the same place!");
    }
}

MazeCard Maze::insertLastPushedOutMazeCardAt(const MazePosition &position)
{
    MazeCard pushedOutMazeCard;
    requireInserrable(position);
    if (isOnSide(position, UP)) {
        insertUpSide(pushedOutMazeCard, position);
    } else if (isOnSide(position, DOWN)) {
        insertDownSide(pushedOutMazeCard, position);
    } else if (isOnSide(position, LEFT)) {
        insertLeftSide(pushedOutMazeCard, position);
    } else if (isOnSide(position, RIGHT)) {
        insertRightSide(pushedOutMazeCard, position);
    } else {
        throw std::invalid_argument("The insertion should be on a side!");
    }
    cards_[position.getRow()][position.getColumn()] = lastPushedOutMazeCard_;
    return lastPushedOutMazeCard_ = pushedOutMazeCard;
}

void Maze::insertUpSide(MazeCard &ejected_card, const MazePosition &position){
    ejected_card = cards_[SIZE - 1][position.getColumn()];
    for(unsigned i{SIZE-1}; 0<i; --i){
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
    for(unsigned i{SIZE-1}; 0<i; --i){
        cards_[position.getRow()][i] = cards_[position.getRow()][i-1];
    }
}

void Maze::insertRightSide(MazeCard &ejected_card, const MazePosition &position){
    ejected_card = cards_[position.getRow()][0];
    for(unsigned i{0}; i<SIZE; ++i){
        cards_[position.getRow()][i] = cards_[position.getRow()][i+1];
    }
}

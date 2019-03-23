#include "Maze.h"
#include <stdexcept>

namespace labyrinth {

MazeCard Maze::insertAt(const MazeCard &mazeCard, const MazePosition &position)
{
// TODO: est-ce une position movable?
//    MazeCard expulsed = cards_.at(position.getRow()).back();
//    cards_.at(position.getRow()).pop_back();
//    cards_.at(position.getRow()).push_front(mazeCard);
//    return expulsed;
    if(outOfBoard(position)){
        throw std::invalid_argument("The position is out of board");
    }

    if(!canBeMoved(position)){
        throw std::logic_error("This card is steady. She can't be moved");
    }

    MazeCard expulsed_card{};

    if(position.getRow() == 0){
        insertUp(mazeCard, expulsed_card);
    }else if(position.getRow() == cards_.size()){
        insertDown(mazeCard, expulsed_card);
    }else if(position.getColumn() == 0){
        insertLeft(mazeCard, expulsed_card, position);
    }else{
        insertRight(mazeCard, expulsed_card,position);
    }

    lastMazeCardInserted_ = mazeCard;
    return expulsed_card;
}

bool Maze::outOfBoard(const MazePosition &position)
{
    return position.getColumn()<0 && position.getColumn() > cards_.size() &&
            position.getRow() < 0 && position.getRow() > cards_.size();
}

void Maze::updateAdjacency()
{
    // TODO
}

}

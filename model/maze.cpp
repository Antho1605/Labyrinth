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

    MazeCard expulsed_card{};

    if(position.getRow() == 0){
        expulsed_card = cards_.at(0).back();
        cards_.at(0).push_front(mazeCard);
    }else if(position.getRow() == cards_.size()){
        expulsed_card = cards_.at(cards_.size()).front();
        cards_.at(position.getColumn()).push_back(mazeCard);
    }else if(position.getColumn() == 0){
        expulsed_card = cards_.at(position.getRow()).back();
        cards_.at(position.getRow()).push_front(mazeCard);
    }else{
        expulsed_card = cards_.at(position.getRow()).front();
        cards_.at(position.getRow()).push_back(mazeCard);
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

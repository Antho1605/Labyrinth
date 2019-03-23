#include "MazePosition.h"
#include <sstream>
#include <stdexcept>

namespace labyrinth {

static unsigned requireValidCoordinate(unsigned coo)
{
    std::stringstream errorMessage;
    errorMessage << "Invalid coordinate! " << coo << " was entered but a";
    errorMessage << " coordinate should be positive and smaller than the maze";
    errorMessage << "size.\n";
    if (8u < coo) {
        throw std::logic_error(errorMessage.str());
    }
    return coo;
}

static void requireValidPosition(unsigned row, unsigned column)
{
    requireValidCoordinate(row);
    requireValidCoordinate(column);
}

MazePosition::MazePosition(unsigned row, unsigned column)
    : row_{requireValidCoordinate(row)},
      column_{requireValidCoordinate(column)}
{}

void MazePosition::moveTo(unsigned row, unsigned column)
{
    requireValidPosition(row, column);
    row_ = row;
    column_ = column;
}

MazeDirection MazePosition::getDirectionTo(const MazePosition &neighbor) const
{
    requireValidPosition(neighbor.getRow(), neighbor.getColumn());
    if (row_ == neighbor.row_ && column_ == neighbor.column_) {
        throw std::logic_error("Trying to get the direction to itself.\n");
    } else if (row_ == neighbor.row_) {
        return column_ < neighbor.column_ ? MazeDirection::RIGHT : MazeDirection::LEFT;
    } else if (column_ == neighbor.column_){
        return row_ < neighbor.row_ ? MazeDirection::DOWN : MazeDirection::UP;
    } else {
        throw std::logic_error("Trying to get direction to a non neighbor.\n");
    }
}

}

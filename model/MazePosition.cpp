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

}

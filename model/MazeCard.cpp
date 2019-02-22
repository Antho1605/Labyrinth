#include "MazeCard.h"

namespace labyrinth {

MazeCard::MazeCard(const MazeCard::Shape &shape, bool isMovable)
    : shape_{shape}, isMovable_{isMovable}
{}

}

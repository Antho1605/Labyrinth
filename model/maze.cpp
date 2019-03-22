#include "Maze.h"

#include <vector>

namespace labyrinth {

MazeCard Maze::insertAt(const MazeCard &mazeCard, const MazePosition &position)
{
    // TODO: est-ce une position movable?
    //    MazeCard expulsed = cards_.at(position.getRow()).back();
    //    cards_.at(position.getRow()).pop_back();
    //    cards_.at(position.getRow()).push_front(mazeCard);
    //    return expulsed;
}

bool Maze::areNeigbors(const MazePosition &lhs, const MazePosition &rhs) const
{
    // TODO
    // Regarder si un chemin existe de  lhs à rhs
    // Regarder si un chemin existe de  rhs à lhs
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
    // TODO
    for (auto const &adjacency : adjacencies_) {
        MazePosition position = adjacency.first;
        std::vector<MazePosition> neighbors = adjacency.second;
        neighbors.clear();
        for (int direction = 0; direction < 4; ++direction) {
            MazePosition neighbor = getNeighbor(position, direction);
            //si estValide(direction) ET sontVoisins(position, voisin) alors
            //   position.ajouter(voisin)
            if (areNeigbors(position, neighbor)) {
                neighbors.push_back(neighbors);
            }
        }
    }

}

}

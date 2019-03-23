#ifndef MAZE_H
#define MAZE_H

#include <map>
#include <vector>
#include <deque>

#include "MazePosition.h"
#include "MazeCard.h"

namespace labyrinth {

/**
 * @brief Represents the maze of the game.
 */
class Maze
{

private:

    /**
     * @brief Is the last maze card that has been inserted in this maze. It is
     * not possible to insert aa new maze card at its position.
     */
    MazeCard lastMazeCardInserted_;

    /**
     * @brief Represents the adjacencies of this maze cards.
     */
    typedef std::map<MazePosition, std::vector<MazePosition>> Graph;
    Graph adjacencies_;

    /**
     * @brief are the cards inside of this maze.
     */
    std::deque<std::deque<MazeCard>> cards_;

public:

    Maze() = default;

    Maze(const Maze&) = default;

    /**
     * @brief Inserts the given maze card in this maze at the given position.
     *
     * The position must be the one of a movable maze card and bust be different
     * than the position of last inserted card.
     *
     * @param mazeCard is the maze card to insert in this maze.
     * @param position is the position of the maze card to insert.
     * @return the maze card that has been pushed out.
     */
    MazeCard insertAt(const MazeCard &mazeCard, const MazePosition &position);

    bool outOfBoard(const MazePosition &position);

    void updateAdjacency();

    /**
     * @brief Tells if a maze card can be inserted at the given position.
     * @return true if a maze card can be inserted at the given position.
     */
    bool isInserrable(MazePosition position) const;

    Maze& operator =(const Maze& otherMaze);

    void insertUp(const MazeCard &mazeCard, MazeCard &expulsed_card)
    {
        expulsed_card = cards_.at(0).back();
        cards_.at(0).pop_back();
        cards_.at(0).push_front(mazeCard);
    }

    void insertDown(const MazeCard &mazeCard, MazeCard &expulsed_card)
    {
        expulsed_card = cards_.at(cards_.size()).front();
        cards_.at(cards_.size()).pop_front();
        cards_.at(cards_.size()).push_back(mazeCard);
    }

    void insertLeft(const MazeCard &mazeCard, MazeCard &expulsed_card, const MazePosition &position)
    {
        expulsed_card = cards_.at(position.getRow()).back();
        cards_.at(position.getRow()).pop_back();
        cards_.at(position.getRow()).push_front(mazeCard);
    }

    void insertRight(const MazeCard &mazeCard, MazeCard &expulsed_card, const MazePosition &position)
    {
        expulsed_card = cards_.at(position.getRow()).front();
        cards_.at(position.getRow()).pop_front();
        cards_.at(position.getRow()).push_back(mazeCard);
    }

    bool canBeMoved(const MazePosition &position)
    {
        return cards_.at(position.getColumn()).at(position.getRow()).isMovable();
    }
};

}

#endif // MAZE_H

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
struct Maze
{

static constexpr unsigned SIZE = 7;

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
    MazeCard cards_[SIZE][SIZE];

    void initializeCards();

    void initializeAdjacency();

public:

    Maze() = default;

    Maze(const Maze&) = default;

    void initialize();

    void updateAdjacency();

    void setCardAt(const MazePosition &position, const MazeCard &card) {
        cards_[position.getRow()][position.getColumn()] = card;
    }

    /**
     * @brief Gets the card located at the given position.
     *
     * @param position is the position of the card to get.
     * @return the card at the given position.
     */
    const MazeCard &getCardAt(const MazePosition &position) const {
        return cards_[position.getRow()][position.getColumn()];
    }

    /**
     * @brief Tells if the maze cards are linked by a path.
     *
     * @param lhs is the first maze card.
     * @param rhs is the second maze card.
     * @return true if the two maze cards at the given positions are linked by a path.
     */
    bool existPathBetween(const MazePosition &lhs, const MazePosition &rhs) const;

    /**
     * @brief Tells if the given positions are adjacent.
     *
     * Two adjacent positions are linked by a path.
     *
     * @param source is the source position.
     * @param dest is the destination position.
     * @return true if the two position are adjacent.
     */
    bool areAdjacent(const MazePosition &source, const MazePosition &dest) const;

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

    /**
     * @brief Tells if the given position is out og this maze bounds.
     *
     * @param position is the position to check.
     * @return true if the position is out of bounds.
     */
    bool isOutOfBounds(const MazePosition &position);

    /**
     * @brief Tells if a maze card can be inserted at the given position.
     * @return true if a maze card can be inserted at the given position.
     */
    bool isInserrable(MazePosition position) const;

    // TODO: méthodes qui permet de trouver un chemin à partir d'une position
    // La méthode retourne la liste des chemins possible en partant d'une postion
    // La classe path contient une liste de positions. Elle a une méthode qui permet
    // de savoir si une position donnée est sur son chemin
    // std::vector<MazePath> getPossiblePaths(MazePosition start);

    Maze& operator =(const Maze& that);

};

}

#endif // MAZE_H

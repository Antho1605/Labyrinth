#ifndef MAZE_H
#define MAZE_H

#include <map>
#include <vector>

#include "MazePosition.h"
#include "MazeCard.h"

namespace labyrinth { namespace model {

/**
 * @brief Represents the maze of the game.
 */
struct Maze
{

static constexpr unsigned SIZE = 7;

private:

    /**
     * @brief is the last maze card that has been pushed out this maze.
     */
    MazeCard lastPushedOutMazeCard_;

    /**
     * @brief is the previous position in this maze of the last maze card that
     * has been pushed out.
     */
    MazePosition lastPushedOutPosition_;

    /**
     * @brief Represents the adjacencies of this maze cards.
     */
    std::map<MazePosition, std::vector<MazePosition>> adjacencies_;

    /**
     * @brief are the cards inside of this maze.
     */
    MazeCard cards_[SIZE][SIZE];

    void initializeCards();

    void initializeAdjacency();

public:

    /**
     * @brief Constructs a maze of 7 by 7 maze cards. A maze contains:
     *    - 16 steady cards which are always at the same spot.
     *    - 34 movable cards which are randomly set on this maze.
     *
     * 12 of the cards are marked with an objective.
     */
    Maze() { initialize(); }

    /**
     * @brief Initializes this maze. The cards are set up.
     */
    void initialize();

    /**
     * @brief Updates the adjacency of this maze cards.
     */
    void updateAdjacency();

    /**
     * @brief Sets the given cards in this maze at the given position.
     *
     * @param position is the position of the card.
     * @param card is the card to set.
     */
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

    MazeCard &getLastPushedOutMazeCard() {return lastPushedOutMazeCard_;}

    MazePosition getLastPushedOutMazePosition()const {return lastPushedOutPosition_;}

    std::vector<MazePosition> getNeighbors(const MazePosition &pos) const;

    /**
     * @brief Tells if the maze cards are directly linked by a path.
     *
     * @param lhs is the first maze card.
     * @param rhs is the second maze card.
     * @return true if the two maze cards at the given positions are linked by a path.
     */
    bool existDirectPathBetween(const MazePosition &lhs, const MazePosition &rhs) const;

    /**
     * @brief Tells if the two position are linked by a path in this maze.
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
     * @brief Inserts the last pushed out maze card in this maze at the given
     * position.
     *
     * The position must be the one of a movable maze card, must be different
     * than the position of last pushed out card and must be on a side of this
     * maze.
     *
     * @param position is the position of the maze card to insert.
     * @return the maze card that has been pushed out.
     */
    MazeCard insertLastPushedOutMazeCardAt(const MazePosition &position);

    /**
     * @brief Tells if the given position is out og this maze bounds.
     *
     * @param position is the position to check.
     * @return true if the position is out of bounds.
     */
    bool isOutOfBounds(const MazePosition &position);

    /**
     * @brief isOnSide tells if the given position is on a maze's side
     * corresponding to the given position.
     *
     * @param position the position to test.
     * @param dir is the direction of the side.
     * @return true if the given position is on a maze's side.
     */
    bool isOnSide(const MazePosition &position, const MazeDirection dir) const;

    /**
     * @brief isOnSide tells if the given position is on a maze's side.
     * @param position the position to test
     * @return true if the given position is on a maze's side.
     */
    bool isOnASide(const MazePosition &position) const;

    /**
     * @brief Maze::insertUpSide insert a card on the maze's upper side
     * @param ejected_card the ejected card
     * @param position the position where to insert.
     */
    void insertUpSide(MazeCard &ejected_card, const MazePosition &position);

    /**
     * @brief Maze::insertDownSide insert a card on the maze's down side
     * @param ejected_card the ejected card
     * @param position the position where to insert.
     */
    void insertDownSide(MazeCard &ejected_card, const MazePosition &position);

    /**
     * @brief Maze::insertLeftSide insert a card on the maze's left side
     * @param ejected_card the ejected card
     * @param position the position where to insert.
     */
    void insertLeftSide(MazeCard &ejected_card, const MazePosition &position);

    /**
     * @brief Maze::insertRightSide insert a card on the maze's right side.
     * @param ejected_card the ejected card
     * @param position the position where to insert.
     */
    void insertRightSide(MazeCard &ejected_card, const MazePosition &position);

    MazePosition getOpposite(const MazePosition &pos);

    /**
     * @brief Requires a inserrable position. An inserrable position is on a side
     * and different from the last push out position.
     * @param position
     */
    void requireInserrable(const MazePosition &position) const;

    Maze& operator =(const Maze& that);

};

}}

#endif // MAZE_H

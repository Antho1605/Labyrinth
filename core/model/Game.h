#ifndef GAME_H
#define GAME_H
#include <vector>
#include "MazeCard.h"
#include "Player.h"
#include "Maze.h"
#include "MazePosition.h"

namespace labyrinth {

/**
 * @brief Represents the game.
 */
class Game
{
    /**
     * @brief is the maze of this game.
     */
    Maze maze_;

    /**
     * @brief Is the last maze card pushed out of the maze.
     */
    MazeCard currentMazeCard_;

    /**
     * @brief Is the position the current player wants to move to.
     */
    MazePosition selectedPlayerPosition_;

    /**
     * @brief Is the position the current player wants to insert the last pushed
     * out card at.
     */
    MazePosition selectedInsertionPosition_;

    /**
     * @brief is the current player. He is the one playing the current turn.
     */
    unsigned currentPlayerIndex_;

    /**
     * @brief Are the players playing this game.
     */
    std::vector<Player> players_;

public:

    static unsigned TOTAL_NB_OF_OBJECTIVES;

    /**
     * @brief Is the maximal number of players that are allowed to take part in
     * this game.
     */
    static unsigned MAX_NB_OF_PLAYERS;

    /**
     * @brief Is the minimal number of players that are allowed to take part in
     * this game.
     */
    static unsigned MIN_NB_OF_PLAYERS;

    /**
     * @brief constructs this game with the given number of players. Initially
     * currentPlayer is the youngest one.
     *
     * @param nbOfPlayers is the number of player of this game. By default, the
     * number of players is set to 4 (maximal capacity);
     */
    Game(unsigned nbOfPlayers=MAX_NB_OF_PLAYERS);

    /**
     * @brief Gets this game maze.
     *
     * @return this game maze.
     */
    const Maze &getMaze() const {return maze_; }

    /**
     * @brief Gets the players that are taking part to this game.
     *
     * @return the players of this game.
     */
    std::vector<Player> getPlayers() const {return players_;}

    /**
     * @brief Gets the piece position the current player has selected.
     *
     * @return the piece position the current player has selected.
     */
    MazePosition getSelectedPlayerPosition() const {
        return selectedPlayerPosition_;
    }

    /**
     * @brief Gets the piece position the current player has selected to insert
     * the last pushed out card.
     *
     * @return the piece position the current player has selected.
     */
    MazePosition getSelectedInsertionPosition() const {
        return selectedInsertionPosition_;
    }

    MazeCard getCurrentMazeCard() const {return currentMazeCard_;}

    /**
     * @brief Gets the current player of this game.
     *
     * @return the current player of this game.
     */
    Player getCurrentPlayer() const { return players_.at(currentPlayerIndex_); }

    /**
     * @brief Gets the current player of this game.
     *
     * @return the current player of this game.
     */
    Player &getCurrentPlayer() { return players_.at(currentPlayerIndex_); }

    /**
     * @brief Tells if oone of the player is at the given position.
     *
     * @param position is the position of a player.
     * @return true if there is a player at the given position.
     */
    bool isAPlayerAt(const MazePosition &position) const {
        for (auto const &player : players_) {
            if (player.isAt(position)) return true;
        }
        return false;
    }

    /**
     * @brief Tells if oone of the player is at the given position.
     *
     * @param position is the position of a player.
     * @return true if there is a player at the given position.
     */
    Player getPlayerAt(const MazePosition &position) const {
        for (auto const &player : players_) {
            if (player.isAt(position)) return player;
        }
        return Player();
    }

    /**
     * @brief Starts this game.
     */
    void start(unsigned nbOfPlayer);

    /**
     * @brief Selects the position of the current player.
     *
     * @param position is the position of the current player.
     */
    void selectPlayerPosition(const MazePosition &position);

    /**
     * @brief Selects the position where to insert currentMazeCard in the maze.
     *
     * @param position is the new position of the currentMazeCard.
     */
    void selectInsertionPosition(const MazePosition &position);

    /**
     * @brief Passes the hand
     */
    void nextPlayer();

    /**
     * @brief Tells if this game is over.
     *
     * @return true if this game is over.
     */
    bool isOver() const;

    /**
     * @brief movePathWays Allows to the current player to insert the card in
     * the maze and sets his state to moving_pathways.
     */
    void movePathWays();

    /**
     * @brief Moves the current player to the selected position.
     */
    void moveCurrentPlayer();

    /**
     * @brief isLastPlayer Tells if the player is the last player to play.
     * @return true if the current player is the last.
     */
    bool isLastPlayer() const;

    void passCurrentPlayer();

};


}

#endif // GAME_H

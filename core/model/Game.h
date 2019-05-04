#ifndef GAME_H
#define GAME_H

#include <vector>
#include "MazeCard.h"
#include "Player.h"
#include "Maze.h"
#include "MazePosition.h"
#include "observer/Subject.h"

namespace labyrinth { namespace model {

/**
 * @brief Represents the game.
 */
class Game : public nvs::Subject
{

    /**
     * @brief is the maze of this game.
     */
    Maze maze_;

    /**
     * @brief Is the last maze card pushed out of the maze.
     */
    MazeCard *currentMazeCard_;

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

    /**
     * @brief Tells if this game is simplified. At the end of a simplified game
     * the winner is the player that has found all of his objectives.
     */
    bool isSimplified_;

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
     * @param isSimplified tell if this game is simplified or not.
     */
    Game(unsigned nbOfPlayers=MAX_NB_OF_PLAYERS, bool isSimplified = false);

    /**
     * @brief Tells if this game is simplified.
     *
     * @return true if this game is simplified.
     */
    bool isSimplified() const { return isSimplified_; }

    /**
     * @brief Gets this game maze.
     *
     * @return this game maze.
     */
    const Maze &getMaze() const {return maze_; }

    /**
     * @brief Gets this game maze.
     *
     * @return this game maze.
     */
    Maze &getMaze() { return maze_; }

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

    MazeCard &getCurrentMazeCard() { return *currentMazeCard_; }

    const MazeCard getCurrentMazeCard() const {
        return *currentMazeCard_;
    }

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
     * @brief Gets the winner of this game. The winner is the first player to
     * find all of his/ her objectives and return to his/ her initial position.
     *
     * @return the winner of this game.
     */
    Player getWinner() const;

    /**
     * @brief Tells if the current player has fount his/ her objective.
     *
     * @return true if the current player has found his/ her objective.
     */
    bool hasCurrentPlayerFoundObjective() const;

    /**
     * @brief Tells if oone of the player is at the given position.
     *
     * @param position is the position of a player.
     * @return true if there is a player at the given position.
     */
    bool isAPlayerAt(const MazePosition &position) const;

    /**
     * @brief Gets the position of the given objective.
     *
     * @param o is the objective to get the position for.
     * @return the position of the given object.
     */
    MazePosition getObjectivePosition(const Object &o) const;

    /**
     * @brief Gets the player(s) at a given position of the maze.
     *
     * @param position is the position of a player.
     * @return player(s) located at the given position in the maze.
     */
    std::vector<Player> getPlayersAt(const MazePosition &position) const;

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
     * @brief Tells if this game is over. A game is over when one of the players
     * found all of his objectives and returned to his/ her initial position.
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

    /**
     * @brief Shifts the players when inserting the current maze card in the
     * maze.
     */
    void shiftPlayer();

    /**
     * @brief shiftPlayerColumn shift the row player when inserting on
     * maze's right or left side.
     * @param player the player to shift.
     */
    void shiftPlayerRow(Player &player);

    /**
     * @brief shiftPlayerColumn shift the column player when inserting on
     * maze's up or down side.
     * @param player the player to shift.
     */
    void shiftPlayerColumn(Player &player);
};

}}

#endif // GAME_H

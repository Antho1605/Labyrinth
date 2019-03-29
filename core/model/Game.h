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
    MazeCard *currentMazeCard_;

    /**
     * @brief selectedPosition is the position selected by the current player.
     */
    MazePosition selectedPlayerPosition_;

    MazePosition selectedCardPosition_;

    /**
     * @brief is the current player. He is the one playing the current turn.
     */
    std::vector<Player>::iterator currentPlayer_;

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

    Maze getMaze() const {return maze_;}

    std::vector<Player> getPlayers() const {return players_;}

    MazePosition getSelectedPlayerPosition(){return selectedPlayerPosition_;}

    MazeCard* getCurrentMazeCard(){return currentMazeCard_;}

    /**
     * @brief Gets the current player of this game.
     *
     * @return the current player of this game.
     */
    Player getCurrentPlayer() const { return *currentPlayer_; }

    /**
     * @brief Starts this game.
     */
    void start(unsigned nbOfPlayer);

    /**
     * @brief Selects the position where to insert currentMazeCard in the maze.
     *
     * @param position is the new position of the currentMazeCard.
     */
    void selectPlayerPosition(const MazePosition &position);

    void selectCardPosition(const MazePosition &position);

    /**
     * @brief Plays the current turn.
     *
     * The current turn can only be played after the insertion othe current player has
     */
    void play();

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

    void movePathWays();

    void moveCurrentPlayer();

};

}

#endif // GAME_H

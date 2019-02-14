#ifndef GAME_H
#define GAME_H
#include <vector>
#include "mazecard.h"
#include "player.h"
#include "maze.h"

namespace labyrinth {

class Game
{
    Maze maze_;
    MazeCard currentMazeCard_;
    Player currentPlayer_;
    std::vector<Player> players_;
    bool isStandard;
public:
    static unsigned MAX_NB_OF_PLAYERS;
    Game(unsigned nbOfPlayers=MAX_NB_OF_PLAYERS);
    void start();
    void nextPlayer();
    bool isOver() const;
};

}

#endif // GAME_H

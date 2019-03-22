#include "Game.h"

namespace labyrinth {

unsigned Game::MAX_NB_OF_PLAYERS = 4;



Game::Game(unsigned nbOfPlayers)
{
    // TODO
}

void Game::start()
{
    // TODO
    // initialiser le labyrinth
    // initialiser les joueurs
    // partager les cartes entre les joueurs
    // set le joueur courant
}

void Game::selectInsertionPosition(const MazePosition &position)
{
    // TODO
}

void Game::play()
{
    // TODO
    // lancer une exception si aucune position n'a été sélectionnée
    // placer la currentMazeCard dans le maze à la position sélectionnée
}

void Game::nextPlayer()
{
    // TODO
    // lancer une exception si le joueur courant n'a pas finit son tour
}

bool Game::isOver() const
{
    // TODO
}

}

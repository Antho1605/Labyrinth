#include "Game.h"
#include <stdexcept>
#include <vector>

namespace labyrinth {

unsigned Game::MAX_NB_OF_PLAYERS = 4;



Game::Game(unsigned nbOfPlayers)
{
    for(unsigned i{0};i<nbOfPlayers; ++i){
        players_.push_back(Player{});
    }
}

void Game::start()
{
    currentPlayer_ = players_.begin();
    // TODO
    // initialiser le labyrinth
    // initialiser les joueurs
    // partager les cartes entre les joueurs
    // set le joueur courant
}

void shareCards(){
    std::vector<ObjectCard> objectCards;
    for(Object object;object != Object::HELMET;object++){
        objectCards.push_back(ObjectCard{object});
    }
}

void Game::selectInsertionPosition(const MazePosition &position)
{
    selectedPosition_ = position;
}

void Game::play()
{
    // TODO
    // lancer une exception si aucune position n'a été sélectionnée
    // placer la currentMazeCard dans le maze à la position sélectionnée
}

void Game::nextPlayer()
{
    if((*currentPlayer_).getState() == Player::State::MOVING_PATHWAYS
            || (*currentPlayer_).getState() == Player::State::MOVING_PIECE){
        throw std::logic_error("The current player has not finished his turn");
    }
    if(currentPlayer_ == players_.end()){
        currentPlayer_ = players_.begin();
    }else{
        currentPlayer_++;
    }
}

bool Game::isOver() const
{
    // TODO
}

}

#include "Game.h"
#include <stdexcept>
#include <vector>

namespace labyrinth {

unsigned Game::MAX_NB_OF_PLAYERS = 4;



Game::Game(unsigned nbOfPlayers)
{
    start(nbOfPlayers);
}

void Game::start(unsigned nbOfPlayers)
{
    for(unsigned i{0};i<nbOfPlayers; ++i){
        Player::Color currentColor{Player::Color::BLUE};
        players_.push_back(Player{currentColor, MazePosition{0,0},ObjectivesDeck{}});
        ++currentColor;
    }

    currentPlayer_ = players_.begin();
    // initialiser les joueurs
    // partager les cartes entre les joueurs
    // set le joueur courant
}

void Game::shareCards(){
    std::vector<ObjectCard> objectCards;
    fillObjectCards(objectCards);
   // std::random_shuffle(objectCards.begin(), objectCards.end());
    size_t size{objectCards.size()};
    std::vector<ObjectCard> objectivesDeck;
    for(unsigned i{0}; i<players_.size();++i){
        for(unsigned j{0}; j<size/players_.size();++j){
            objectivesDeck.push_back(*objectCards.begin());
            objectCards.erase(objectCards.begin());
            players_.at(i).getObjectives() = objectivesDeck;
        }
    }
}

void Game::fillObjectCards(std::vector<ObjectCard> objectCards){
    for(Object object{Object::GHOST};object != Object::HELMET;++object){
        objectCards.push_back(ObjectCard{object});
    }
}

void Game::selectInsertionPosition(const MazePosition &position)
{
    selectedPosition_ = position;
}

void Game::play()
{
    maze_.insertAt(*currentMazeCard_,selectedPosition_);
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
    (*currentPlayer_).setState(Player::State::WAITING);
    if(currentPlayer_ == players_.end()){
        currentPlayer_ = players_.begin();
    }else{
        currentPlayer_++;
    }
    (*currentPlayer_).setState(Player::State::MOVING_PATHWAYS);
}

bool Game::isOver() const
{
    // TODO
}

}

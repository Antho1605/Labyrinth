#include "Game.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

namespace labyrinth {

unsigned Game::TOTAL_NB_OF_OBJECTIVES = 24;
unsigned Game::MIN_NB_OF_PLAYERS = 2;
unsigned Game::MAX_NB_OF_PLAYERS = 4;

Game::Game(unsigned nbPlayers)
{
    if (nbPlayers < MIN_NB_OF_PLAYERS || MAX_NB_OF_PLAYERS < nbPlayers)
        throw logic_error(to_string(nbPlayers) + " is not a valid number of player!");
    start(nbPlayers);
}

static vector<ObjectCard> constructObjectives()
{
    vector<ObjectCard> objectives;
    for(Object object{Object::GHOST}; object <= Object::HELMET; ++object){
        objectives.push_back(object);
    }
    random_shuffle(objectives.begin(), objectives.end());
    return objectives;
}

static ObjectCard remove(std::vector<ObjectCard> &objectives) {
    ObjectCard objective = objectives.back();
    objectives.pop_back();
    return objective;
}

static ObjectivesDeck constructObjectivesDeck(vector<ObjectCard> &objectives,
                                              size_t nbPlayers)
{
    vector<ObjectCard> deck;
    unsigned nbObjectives = Game::TOTAL_NB_OF_OBJECTIVES / nbPlayers;
    for (unsigned i = 0; i < nbObjectives; ++i)
        deck.push_back(remove(objectives));
    return ObjectivesDeck{deck};
}

static void dealObjectives(std::vector<Player> &players) {
    vector<ObjectCard> objectives = constructObjectives();
    for(auto &player : players) {
        player.setObjectives(constructObjectivesDeck(objectives, players.size()));
    }
}

void Game::start(unsigned nbOfPlayers)
{
    Player::Color currentColor{Player::Color::RED};
    for (unsigned i = 0; i < nbOfPlayers; ++i) {
        players_.push_back(Player{currentColor});
        ++currentColor;
    }
    dealObjectives(players_);
    currentPlayer_ = players_.begin();
}

void Game::selectPlayerPosition(const MazePosition &position)
{
    selectedPlayerPosition_ = position;
}

void Game::selectCardPosition(const MazePosition &position){
    selectedCardPosition_= position;
}

void Game::movePathWays(){
    (*currentPlayer_).setState(Player::State::MOVING_PATHWAYS);
    maze_.insertLastPushedOutMazeCardAt(selectedCardPosition_);
    (*currentPlayer_).setState(Player::State::MOVING);
}

void Game::moveCurrentPlayer(){
    if((*currentPlayer_).isMoving()){
        (*currentPlayer_).moveTo(selectedPlayerPosition_.getRow(),
                                 selectedPlayerPosition_.getColumn());
    }else{
        throw std::logic_error("You need to insert a maze card in the "
                               "labyrinth before moving your piece!");
    }

}

void Game::nextPlayer()
{
    if((*currentPlayer_).isMovingPathWays()
            || (*currentPlayer_).isMoving()){
        throw std::logic_error("The current player has not finished his turn");
    }
    if(isLastPlayer()){
        currentPlayer_ = players_.begin();
    }else{
        currentPlayer_++;
    }
    (*currentPlayer_).setState(Player::State::MOVING_PATHWAYS);
}

bool Game::isLastPlayer(){
    return currentPlayer_ == players_.end();
}

bool Game::isOver() const
{
    return (*currentPlayer_).hasFoundAllObjectives();
    //Le joueur doit être retourné à sa position initiale.
}

}

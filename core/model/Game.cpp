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

void Game::selectInsertionPosition(const MazePosition &position) {
    maze_.requireInserrable(position);
    selectedInsertionPosition_= position;
}

void Game::movePathWays(){
    //Si le joueur est en dehors du lab après avoir inseré la carte, il doit
    //être déplacé au côté opposé.
    if(!getCurrentPlayer().isWaiting() || getCurrentPlayer().hasMovedPathWays()){
        throw std::logic_error("You already inserted a card!");
    }
    maze_.insertLastPushedOutMazeCardAt(selectedInsertionPosition_);
    getCurrentPlayer().setState(Player::State::MOVED_PATHWAYS);
}

void Game::moveCurrentPlayer(){
    if(!getCurrentPlayer().hasMovedPathWays()){
        throw std::invalid_argument("You need to insert the card in the "
                                    "labyrinth before moving your piece!");
    }else if(getCurrentPlayer().hasMoved()){
        throw std::invalid_argument("You already moved your piece!");
    }

    getCurrentPlayer().moveTo(selectedPlayerPosition_.getRow(),
                                 selectedPlayerPosition_.getColumn());
    getCurrentPlayer().setState(Player::State::MOVED_PIECE);
}

void Game::nextPlayer()
{
    if(getCurrentPlayer().isWaiting()){
        throw std::logic_error("The current player has not finished his turn");
    }
    if(isLastPlayer()){
        currentPlayer_ = players_.begin();
    }else{
        currentPlayer_++;
    }
    getCurrentPlayer().setState(Player::State::WAITING);
}

bool Game::isLastPlayer() const{
    return currentPlayer_ == players_.end();
}

bool Game::isOver() const
{
    for(auto &player : players_){
        if(player.isReturnedToInitialPos() && player.hasFoundAllObjectives()){
            return true;
        }
    }
    return false;
}



}

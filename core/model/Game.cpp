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

Game::Game(unsigned nbPlayers) : currentPlayerIndex_{0}
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

static MazePosition getStartPosition(unsigned player) {
    switch (player)
    {
    case 0:
        return MazePosition(0, 0);
    case 1:
        return MazePosition(0, 6);
    case 2:
        return MazePosition(6, 0);
    case 3:
        return MazePosition(6, 6);
    default:
        throw std::logic_error(to_string(player) + " is not a valid player id.");
    }
}

static void setPlayersStartPosition(std::vector<Player> &players) {
    for (unsigned player = 0; player < players.size(); ++player) {
        MazePosition pos = getStartPosition(player);
        players.at(player).moveTo(pos.getRow(), pos.getColumn());
    }
}

void Game::start(unsigned nbOfPlayers)
{
    Player::Color currentColor{Player::Color::RED};
    for (unsigned i = 0; i < nbOfPlayers; ++i) {
        players_.push_back(Player{currentColor});
        ++currentColor;
    }
    setPlayersStartPosition(players_);
    dealObjectives(players_);
    currentMazeCard_ = maze_.getLastPushedOutMazeCard();
}

void Game::selectPlayerPosition(const MazePosition &position)
{
    MazePosition playerPosition = getCurrentPlayer().getPosition();
    if (!maze_.existPathBetween(playerPosition, position)) {
        throw std::logic_error("There is no way leading to this position");
    }
    selectedPlayerPosition_ = position;
}

void Game::selectInsertionPosition(const MazePosition &position) {
    maze_.requireInserrable(position);
    selectedInsertionPosition_= position;
}

void Game::movePathWays() {
    if(!getCurrentPlayer().isWaiting() || getCurrentPlayer().isReadyToMove()){
        throw std::logic_error("You already inserted a card!");
    }
    maze_.insertLastPushedOutMazeCardAt(selectedInsertionPosition_);
    currentMazeCard_ = maze_.getLastPushedOutMazeCard();
    getCurrentPlayer().setReadyToMove();
    shiftPlayer();
}

void Game::shiftPlayer(){

    for(auto &player : players_){
        if(player.getPosition() == maze_.getOpposite(selectedInsertionPosition_)){
            player.setPosition(selectedInsertionPosition_);
        }else{
            if(player.getPosition().getRow() == selectedInsertionPosition_.getRow()){
                shiftPlayerRow(player);
            }

            if(player.getPosition().getColumn() == selectedInsertionPosition_.getColumn()){
                shiftPlayerColumn(player);
            }
        }
    }
}
void Game::shiftPlayerRow(Player &player){
    unsigned row;
    unsigned column;

    if(maze_.isOnSide(selectedInsertionPosition_,RIGHT)){
        row = player.getPosition().getRow();
        column = player.getPosition().getColumn()- 1;
        player.setPosition(MazePosition{row,column});
    }else if(maze_.isOnSide(selectedInsertionPosition_,LEFT)){
        row = player.getPosition().getRow();
        column = player.getPosition().getColumn()+ 1;
        player.setPosition(MazePosition{row,column});
    }
}

void Game::shiftPlayerColumn(Player &player){
    unsigned row;
    unsigned column;

    if(maze_.isOnSide(selectedInsertionPosition_,UP)){
        row = player.getPosition().getRow() + 1;
        column = player.getPosition().getColumn();
        player.setPosition(MazePosition{row,column});
    }else if(maze_.isOnSide(selectedInsertionPosition_,DOWN)){
        row = player.getPosition().getRow() - 1;
        column = player.getPosition().getColumn();
        player.setPosition(MazePosition{row,column});
    }
}
void Game::moveCurrentPlayer() {
    if(!getCurrentPlayer().isReadyToMove()){
        throw std::invalid_argument("You need to insert the card in the "
                                    "labyrinth before moving your piece!");
    }
    if(getCurrentPlayer().isDone()){
        throw std::invalid_argument("You already moved your piece!");
    }
    getCurrentPlayer().moveTo(selectedPlayerPosition_.getRow(),
                              selectedPlayerPosition_.getColumn());
    getCurrentPlayer().setDone();
    MazeCard card = maze_.getCardAt(getCurrentPlayer().getPosition());
    const Object current = getCurrentPlayer().getCurrentObjective().getObject();
    if (card.getObject() == current) {
        getCurrentPlayer().turnCurrentObjectiveOver();
    }
}

void Game::nextPlayer()
{
    if(!getCurrentPlayer().isDone()){
        throw std::logic_error("The player is not done playing!");
    }
    if (currentPlayerIndex_ == players_.size() - 1) {
        currentPlayerIndex_ = 0;
    } else {
        currentPlayerIndex_++;
    }
    getCurrentPlayer().setWaiting();
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

void Game::passCurrentPlayer(){
    getCurrentPlayer().setDone();
    nextPlayer();
}


}

#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../MazePosition.h"
#include "../Player.h"
#endif

using namespace labyrinth;

TEST_CASE("Not enough mazeCards in the objectivesStack" , "[player]") {
    std::vector <ObjectCard> objectivesStack;
    objectivesStack.push_back(ObjectCard {Object::BAT});
    REQUIRE_THROWS_AS((Player{Player::PlayerColor::BLUE, 19,MazePosition{0,0}, objectivesStack}),std::invalid_argument);
}

TEST_CASE("To much mazeCards in the objectivesStack"){
    std::vector <ObjectCard> objectivesStack;
    for(int i{0}; i != static_cast<int>(Object::PURSE_OF_GOLD);++i){
        objectivesStack.push_back(static_cast<Object>(i));
    }
    REQUIRE_THROWS_AS((Player{Player::PlayerColor::BLUE, 19,MazePosition{0,0}, objectivesStack}),std::invalid_argument);
}

TEST_CASE("The player is created whithout exception"){
    std::vector <labyrinth::ObjectCard> objectivesStack;
    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
        objectivesStack.push_back(static_cast<Object>(i));
    }
    REQUIRE_NOTHROW(Player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack});
}

TEST_CASE("Test of the getters of a new player"){
    std::vector <ObjectCard> objectivesStack;
    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
        objectivesStack.push_back(static_cast<Object>(i));
    }
    Player player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack};
    REQUIRE(player.getColor_() == Player::PlayerColor::BLUE);
    REQUIRE(player.getAge_() == 19);
    REQUIRE(player.getCurrentObjective_() == nullptr);
    REQUIRE(player.getPosition().column == 0);
    REQUIRE(player.getPosition().row == 0);
}

TEST_CASE("Passes to the right card"){
    std::vector<ObjectCard> objectivesStack;
    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
        objectivesStack.push_back(static_cast<Object>(i));
    }
    Player player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack};
    player.nextObjective();
    REQUIRE(player.getCurrentObjective().getObject() == Object::GHOST);
    player.nextObjective();
    REQUIRE(player.getCurrentObjective().getObject() == Object::GNOME);
    player.nextObjective();
    REQUIRE(player.getCurrentObjective().getObject() == Object::DRAGON);
}







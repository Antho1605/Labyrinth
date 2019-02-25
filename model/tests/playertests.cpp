#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../MazePosition.h"
#include "../Player.h"
#include "objectivesdeck.h"
#include <stdexcept>
#endif

using namespace labyrinth;

TEST_CASE("The size of the objectives is wrong" , "[player]") {

    std::vector<ObjectCard> objectives;
    objectives.push_back(ObjectCard {Object::BAT});
    REQUIRE_THROWS_AS((Player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},
    ObjectivesDeck{objectives}}),std::invalid_argument);
}

TEST_CASE("The player is created whithout exception"){
    std::vector<ObjectCard> objectives;
    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
        objectives.push_back(ObjectCard{static_cast<Object>(i)});
    }
    ObjectivesDeck objectivesStack{objectives};
    REQUIRE_NOTHROW(Player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack});
}

TEST_CASE("Test the getters of a new player"){
    std::vector<ObjectCard> objectives;
    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
        objectives.push_back(ObjectCard{static_cast<Object>(i)});
    }
    ObjectivesDeck objectivesStack{objectives};
    Player player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack};
    CHECK(player.getColor_() == Player::PlayerColor::BLUE);
    CHECK(player.getAge_() == 19);
    CHECK(player.getCurrentObjective_() == nullptr);
    CHECK(player.getPosition().column == 0);
    CHECK(player.getPosition().row == 0);
    CHECK(player.getState() == Player::PlayerState::WAITING);
}

//TEST_CASE("Passes to the right card"){
//    std::vector<ObjectCard> objectives;
//    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
//        objectives.push_back(ObjectCard{static_cast<Object>(i)});
//    }
//    ObjectivesDeck objectivesDeck{objectives};
//    Player player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesDeck};
////    player.nextObjective();
////    REQUIRE(player.getCurrentObjective().getObject() == Object::GHOST);
////    player.nextObjective();
////    REQUIRE(player.getCurrentObjective().getObject() == Object::GNOME);
////    player.nextObjective();
////    REQUIRE(player.getCurrentObjective().getObject() == Object::DRAGON);
//}

//TEST_CASE("The card is turned over after call of nextObjective"){
//    std::vector<ObjectCard> objectives;
//    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
//        objectives.push_back(ObjectCard{static_cast<Object>(i)});
//    }
//    ObjectivesDeck objectivesStack{objectives};
//    Player player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack};
//    player.nextObjective();
//    player.nextObjective();
//    REQUIRE(player.getObjectives().getDeck_()[0].isTurnedOver());
//}

//TEST_CASE("The player found all his objectives"){

//    std::vector<ObjectCard> objectives;
//    for(unsigned i{0}; i != static_cast<int>(Object::OWL);++i){
//        objectives.push_back(ObjectCard{static_cast<Object>(i)});
//    }
//    ObjectivesDeck objectivesStack{objectives};
//    Player player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack};

//    for(unsigned j{0}; j<=player.getObjectives().getDeck_().size();++j){
//        player.nextObjective();
//    }
//    CHECK(player.hasFoundAllObjectives());
//}

//TEST_CASE("NextPlayer when all objectives have been found"){
//    std::vector<ObjectCard> objectives;
//    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
//        objectives.push_back(ObjectCard{static_cast<Object>(i)});
//    }
//    ObjectivesDeck objectivesStack{objectives};
//    Player player{Player::PlayerColor::BLUE, 19,MazePosition{0,0},objectivesStack};

//    for(unsigned i{0}; i<=player.getObjectives().getDeck_().size();++i){
//        player.nextObjective();
//    }
//    REQUIRE_THROWS_AS(player.nextObjective(),std::logic_error);
//}






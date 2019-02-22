#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../model/MazePosition.h"
#include "../model/Player.h"
#endif


TEST_CASE("Bad creation of player") {

    MazePosition mazePosition{0,0};
    std::vector <labyrinth::ObjectCard> objectiveStack;
    objectiveStack.push_back(labyrinth::ObjectCard {labyrinth::Object::BAT});
    labyrinth::Player player{labyrinth::Player::PlayerColor::BLUE, 19,mazePosition, objectiveStack};
}

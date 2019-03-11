#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../model/Objectivesdeck.h"
#include <vector>
#include <iostream>
#endif

using namespace labyrinth;

TEST_CASE("Initially, getting current card reads the expected one.")
{
    ObjectivesDeck d{Object::BAT, Object::DRAGON};
    CHECK(d.getCurrentCard()->getObject() == Object::BAT);
}

//TEST_CASE("nextCard twice"){
//    std::vector <ObjectCard> objectCards;
//    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
//        objectCards.push_back(ObjectCard{static_cast<Object>(i)});
//    }
//    ObjectivesDeck objectivesDeckTest{objectCards};
//    CHECK(objectivesDeckTest.nextCard()->getObject() == Object::GHOST);
//    objectivesDeckTest.getDeck_().at(0).turnOver();
//    std::cout << objectivesDeckTest.getDeck_().at(0).isTurnedOver() << std::endl;
//    CHECK(objectivesDeckTest.nextCard()->getObject() == Object::GNOME);
//}

//TEST_CASE("There still objects to be found"){
//    std::vector <ObjectCard> objectCards;
//    for(int i{0}; i != static_cast<int>(Object::OWL);++i){
//        objectCards.push_back(ObjectCard{static_cast<Object>(i)});
//    }
//    ObjectivesDeck objectivesDeckTest{objectCards};
//    CHECK_FALSE(objectivesDeckTest.allObjectivesFound());
//}

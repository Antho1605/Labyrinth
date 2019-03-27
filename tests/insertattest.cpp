#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

#include "Maze.h"

#endif

using namespace labyrinth;

TEST_CASE("The card is inserted as expected on the upper side"){
    Maze maze{};
    MazeCard mazeCard = maze.getLastExpeledMazeCard();
    MazePosition position{0,1};
    maze.insertLastPushedOutMazeCardAt(position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The card is inserted as expected on the down side"){
    Maze maze{};
    MazeCard mazeCard = maze.getLastExpeledMazeCard();
    MazePosition position{6,1};
    maze.insertLastPushedOutMazeCardAt(position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The card is inserted as expected on the left side"){
    Maze maze{};
    MazeCard mazeCard = maze.getLastExpeledMazeCard();
    MazePosition position{1,0};
    maze.insertLastPushedOutMazeCardAt(position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The card is inserted as expected on the right side"){
    Maze maze{};
    MazeCard mazeCard = maze.getLastExpeledMazeCard();
    MazePosition position{1,6};
    maze.insertLastPushedOutMazeCardAt(position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The inserting position should be on a maze's side"){
    Maze maze{};
    MazeCard mazeCard = maze.getLastExpeledMazeCard();
    REQUIRE_THROWS(maze.insertLastPushedOutMazeCardAt(MazePosition{1,4}));
}

TEST_CASE("The inserting card should be a movable card"){
    Maze maze{};
    MazeCard insertedMazeCard{};
    REQUIRE_THROWS(maze.insertLastPushedOutMazeCardAt(MazePosition{0,6}));
}

TEST_CASE("The inserted card should be saved in the last maze card inserted"){
    Maze maze{};
    MazePosition position{0,6};
    MazeCard mazeCard{MazeCardShape{MazeDirection::UP | MazeDirection::RIGHT}};
    maze.insertLastPushedOutMazeCardAt(MazePosition{0,1});
    CHECK(maze.getLastExpeledMazeCard() == mazeCard);
}

TEST_CASE("The returned card should be as expected"){
    Maze maze{};
    MazeCard mazeCard = maze.getLastExpeledMazeCard();
    MazePosition position{1,6};
    MazeCard expectedCard = maze.getCardAt(MazePosition{1,0});
    MazeCard ejectedCard = maze.insertLastPushedOutMazeCardAt(position);
    CHECK(ejectedCard == expectedCard);
}

TEST_CASE("All the mazeCards are swapped correctly to the up side"){
    Maze maze{};
    MazeCard mazeCard{maze.getLastExpeledMazeCard()};
    MazePosition position{0,1};
    std::vector<MazeCard> beforeinsertLastPushedOutMazeCardAt{};
    for(unsigned i{0};i<maze.SIZE-1;++i){
        beforeinsertLastPushedOutMazeCardAt.push_back(maze.getCardAt(MazePosition {i,1}));
    }
    maze.insertLastPushedOutMazeCardAt(position);
    for(unsigned j{0};j<maze.SIZE-1;j++){
        CHECK(beforeinsertLastPushedOutMazeCardAt.at(j) == maze.getCardAt(MazePosition{j+1,1}));
    }
}

TEST_CASE("All the mazeCards are swapped correctly to the down side"){
    Maze maze{};
    MazeCard mazeCard{maze.getLastExpeledMazeCard()};
    MazePosition position{6,1};
    std::vector<MazeCard> beforeinsertLastPushedOutMazeCardAt{};
    for(unsigned i{0};i<maze.SIZE-1;++i){
        beforeinsertLastPushedOutMazeCardAt.push_back(maze.getCardAt(MazePosition {i,1}));
    }
    maze.insertLastPushedOutMazeCardAt(position);
    for(unsigned j{1};j>maze.SIZE-1;++j){
        CHECK(beforeinsertLastPushedOutMazeCardAt.at(j) == maze.getCardAt(MazePosition{j-1,1}));
    }
}

TEST_CASE("All the mazeCards are swapped correctly to the left"){
    Maze maze{};
    MazeCard mazeCard{maze.getLastExpeledMazeCard()};
    MazePosition position{1,0};
    std::vector<MazeCard> beforeinsertLastPushedOutMazeCardAt{};
    for(unsigned i{0};i<maze.SIZE-1;++i){
        beforeinsertLastPushedOutMazeCardAt.push_back(maze.getCardAt(MazePosition {1,i}));
    }
    maze.insertLastPushedOutMazeCardAt(position);
    for(unsigned j{0};j<maze.SIZE-1;j++){
        CHECK(beforeinsertLastPushedOutMazeCardAt.at(j) == maze.getCardAt(MazePosition{1,j+1}));
    }
}

TEST_CASE("All the mazeCards are swapped correctly to the right"){
    Maze maze{};
    MazeCard mazeCard{maze.getLastExpeledMazeCard()};
    MazePosition position{1,6};
    std::vector<MazeCard> beforeinsertLastPushedOutMazeCardAt{};
    for(unsigned i{0};i<maze.SIZE-1;++i){
        beforeinsertLastPushedOutMazeCardAt.push_back(maze.getCardAt(MazePosition {1,i}));
    }
    maze.insertLastPushedOutMazeCardAt(position);
    for(unsigned j{1};j<maze.SIZE-1;j++){
        CHECK(beforeinsertLastPushedOutMazeCardAt.at(j) == maze.getCardAt(MazePosition{1,j-1}));
    }
}

#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/Maze.h"
#endif

using namespace labyrinth;

TEST_CASE("The card is inserted as expected on the upper side"){
    Maze maze{};
    maze.initialize();
    MazeCard mazeCard{};
    MazePosition position{0,1};
    maze.insertAt(mazeCard, position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The card is inserted as expected on the down side"){
    Maze maze{};
    maze.initialize();
    MazeCard mazeCard{};
    MazePosition position{6,1};
    maze.insertAt(mazeCard, position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The card is inserted as expected on the left side"){
    Maze maze{};
    maze.initialize();
    MazeCard mazeCard{};
    MazePosition position{1,0};
    maze.insertAt(mazeCard, position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The card is inserted as expected on the right side"){
    Maze maze{};
    maze.initialize();
    MazeCard mazeCard{};
    MazePosition position{1,6};
    maze.insertAt(mazeCard, position);
    CHECK(maze.getCardAt(position) == mazeCard);
}

TEST_CASE("The inserting position should be on a maze's side"){
    Maze maze{};
    maze.initialize();
    MazeCard mazeCard{};
    REQUIRE_THROWS(maze.insertAt(mazeCard, MazePosition{1,6}));
}

TEST_CASE("The inserting card should be a movable card"){
    Maze maze{};
    maze.initialize();
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    MazeCard insertedMazeCard{};
    REQUIRE_THROWS(maze.insertAt(insertedMazeCard, MazePosition{0,6}));
}

TEST_CASE("The inserted card should be saved in the last maze card inserted"){
    Maze maze{};
    maze.initialize();
    MazePosition position{0,6};
    MazeCard mazeCard{};
    maze.insertAt(mazeCard, MazePosition{0,1});
    REQUIRE(maze.getLastMazeCardInserted() == mazeCard);
}

TEST_CASE("The returned card should be as expected"){
    Maze maze{};
    maze.initialize();
    MazeCard mazeCard{};
    MazePosition position{1,6};
    MazeCard ejectedCard = maze.insertAt(mazeCard, position);
    MazeCard expectedCard = maze.getCardAt(MazePosition{1,0});
    CHECK(ejectedCard == expectedCard);
}








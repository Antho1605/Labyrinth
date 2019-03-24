#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/Maze.h"
#endif

using namespace labyrinth;

TEST_CASE("The card is inserted as expected on the upper side"){

}

TEST_CASE("The card is inserted as expected on the down side"){

}

TEST_CASE("The card is inserted as expected on the left side"){

}

TEST_CASE("The card is inserted as expected on the right side"){

}

TEST_CASE("The inserting position should be on a maze's side"){
//    Maze maze{};
//    maze.initialize();
//    MazeCard mazeCard{};
//    REQUIRE_THROWS(maze.insertAt(mazeCard, MazePosition{1,6}));
}

TEST_CASE("The inserting card should be a movable card"){
//    Maze maze{};
//    maze.initialize();
//    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
//    MazeCard mazeCard{};
//    REQUIRE_THROWS(maze.insertAt(mazeCard, MazePosition{0,6}));
}

TEST_CASE("The ejected card should be saved in the last maze card ejected"){
//    Maze maze{};
//    maze.initialize();
//    MazePosition position{0,6};
//    MazeCard mazeCard{};
//    maze.insertAt(mazeCard, MazePosition{0,1});
//    REQUIRE(maze.getLastMazeCardInserted() == mazeCard);
}

TEST_CASE("The ejected card should be the expected card"){

}

#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>

#include "Maze.h"
#include "MazeDirection.h"

#endif

using namespace labyrinth;

#include <iostream>

TEST_CASE("The maze is initialized as expected")
{
    Maze m;
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            if (row % 2 == 0 && column % 2 == 0) {
                CHECK(!m.getCardAt(MazePosition{row, column}).isMovable());
            } else {
                CHECK(m.getCardAt(MazePosition{row, column}).isMovable());
            }
        }
    }
}

TEST_CASE("isOnSide should return true when the position is on the up side"){
    Maze maze{};
    MazePosition position{0, 3};
    CHECK(maze.isOnSide(position, UP));
}

TEST_CASE("isOnSide should return true when the position is on the right side"){
    Maze maze{};
    MazePosition position{3, 6};
    CHECK(maze.isOnSide(position, RIGHT));
}

TEST_CASE("isOnSide should return true when the position is on the down side"){
    Maze maze{};
    MazePosition position{6, 3};
    CHECK(maze.isOnSide(position, DOWN));
}

TEST_CASE("isOnSide should return true when the position is on the left side"){
    Maze maze{};
    MazePosition position{3, 0};
    CHECK(maze.isOnSide(position, LEFT));
}

TEST_CASE("isOnASide should return true when the position is on the upper side"){
    Maze maze{};
    MazePosition position{0, 3};
    CHECK(maze.isOnASide(position));
}

TEST_CASE("isOnASide should return true when the position is on the left side"){
    Maze maze{};
    MazePosition position{3, 0};
    CHECK(maze.isOnASide(position));
}

TEST_CASE("isOnASide should return true when the position is on the bottom side"){
    Maze maze{};
    MazePosition position{6, 4};
    CHECK(maze.isOnASide(position));
}

TEST_CASE("isOnASide should return true when the position is on the right side"){
    Maze maze{};
    MazePosition position{3, 6};
    CHECK(maze.isOnASide(position));
}

TEST_CASE("requireInserrable should cause an error if the position is steady"){
    Maze maze{};
    MazePosition position{0, 2};
    REQUIRE_THROWS_AS(maze.requireInserrable(position), std::logic_error);
}

TEST_CASE("requireInserrable should cause an error if the position is the last push out position"){
    Maze maze{};
    maze.insertLastPushedOutMazeCardAt({1, 0});
    REQUIRE_THROWS_AS(maze.requireInserrable(MazePosition(1, 6)),
                      std::logic_error);
}

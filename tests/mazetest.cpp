#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/Maze.h"
#endif

using namespace labyrinth;

#include <iostream>

TEST_CASE("The maze is initialized as expected")
{
    Maze m;
    m.initialize();
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

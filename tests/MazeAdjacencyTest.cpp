#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/Maze.h"
#endif

using namespace labyrinth;

TEST_CASE("Two maze cards linked by a direct path should be neigbors")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | DOWN, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    CHECK(m.existPathBetween(a, b));
}

TEST_CASE("Two maze cards that are not directly linked should not be neighbors")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | RIGHT, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_FALSE(m.existPathBetween(a, b));
}

TEST_CASE("existPathBetween throws an exception if the first position is invalid")
{
    Maze m;
    MazePosition b{4, 4};
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_THROWS_AS(m.existPathBetween(MazePosition{6, 8}, b), std::logic_error);
}

TEST_CASE("existPathBetween throws an exception if the second position is invalid")
{
    Maze m;
    MazePosition a{0, 0};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | RIGHT, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_THROWS_AS(m.existPathBetween(a, b), std::logic_error);
}

TEST_CASE("Two maze cards linked by a direct path should be adjacent")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | DOWN, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    m.updateAdjacency();
    CHECK(m.areAdjacent(a, b));
}


#include <iostream>
TEST_CASE("Adjacencies are initialized as expected after maze construction")
{
    Maze m;
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            for (MazeDirection direction = UP; direction <= LEFT; ++direction) {
                MazePosition position{row, column};
                if (position.hasNeighbor(direction)) {
                    MazePosition neighbor = position.getNeighbor(direction);
                    CHECK(m.areAdjacent(position, neighbor));
                }
            }
        }
    }
}

TEST_CASE("Adjacencies are updated after insertion in column.")
{

}

TEST_CASE("If no insertion took place, the maze adjacencies does not update")
{

}

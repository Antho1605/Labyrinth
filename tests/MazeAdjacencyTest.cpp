#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/Maze.h"
#endif

using namespace labyrinth;

TEST_CASE("Two maze cards linked by a direct path should be adjacent")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | DOWN, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    CHECK(m.areAdjacent(a, b));
}

TEST_CASE("Two maze cards that are not directly linked should not be neighbors")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | RIGHT, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_FALSE(m.areAdjacent(a, b));
}

TEST_CASE("areAdjacent throws an exception if the first position is invalid")
{
    Maze m;
    MazePosition b{4, 4};
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_THROWS_AS(m.areAdjacent(MazePosition{6, 8}, b), std::logic_error);
}

TEST_CASE("areNeighbors throws an exception if the second position is invalid")
{
    Maze m;
    MazePosition a{0, 0};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | RIGHT, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_THROWS_AS(m.areAdjacent(a, b), std::logic_error);
}

TEST_CASE("Adjacencies are updated after insertion in row.")
{

}

TEST_CASE("Adjacencies are updated after insertion in column.")
{

}

TEST_CASE("If no insertion took place, the maze adjacencies does not update")
{

}

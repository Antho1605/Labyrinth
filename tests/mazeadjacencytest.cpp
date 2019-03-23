#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/Maze.h"
#endif

using namespace labyrinth;

TEST_CASE("Two maze cards linked by a direct path should be neighbors")
{

}

TEST_CASE("Two maze cards that are not directly linked should not be neighbors")
{

}

TEST_CASE("areNeighbors throws an exception if the first position is invalid")
{

}

TEST_CASE("areNeighbors throws an exception if the second position is invalid")
{

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

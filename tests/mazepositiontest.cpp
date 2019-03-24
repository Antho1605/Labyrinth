#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/MazePosition.h"
#endif

using namespace labyrinth;

TEST_CASE("Gets the direction to a neighbor to the top")
{
    MazePosition source{4, 4};
    MazePosition destination{3, 4};
    CHECK(source.getDirectionTo(destination) == MazeDirection::UP);
}

TEST_CASE("Gets the direction to a neighbor to the right")
{
    MazePosition source{4, 4};
    MazePosition destination{4, 5};
    CHECK(source.getDirectionTo(destination) == MazeDirection::RIGHT);
}

TEST_CASE("Gets the direction to a neighbor to the bottom")
{
    MazePosition source{4, 4};
    MazePosition destination{5, 4};
    CHECK(source.getDirectionTo(destination) == MazeDirection::DOWN);
}

TEST_CASE("Gets the direction to a neighbor to the left")
{
    MazePosition source{4, 4};
    MazePosition destination{4, 3};
    CHECK(source.getDirectionTo(destination) == MazeDirection::LEFT);
}

TEST_CASE("Trying to get the direction to itself causes an exception")
{
    MazePosition source{4, 4};
    REQUIRE_THROWS_AS(source.getDirectionTo(source), std::logic_error);
}

TEST_CASE("Trying to get the direction to a same position causes an exception")
{
    MazePosition source{4, 4};
    MazePosition destination{4, 4};
    REQUIRE_THROWS_AS(source.getDirectionTo(destination), std::logic_error);
}

TEST_CASE("Trying to get the direction to a non neighbor causes an exception")
{
    MazePosition source{4, 4};
    MazePosition destination{5, 5};
    REQUIRE_THROWS_AS(source.getDirectionTo(destination), std::logic_error);
}

TEST_CASE("Getting the upper neighbor of a position should get the expected one")
{
    MazePosition m{4, 4};
    MazePosition neighbor = m.getNeighbor(UP);
    CHECK(neighbor.getRow() == 3);
    CHECK(neighbor.getColumn() == 4);
    CHECK(m.getRow() == 4);
    CHECK(m.getColumn() == 4);
}

TEST_CASE("Getting the upper neighbor of upper side position causes an error")
{
    MazePosition m{0, 4};
    REQUIRE_THROWS_AS(m.getNeighbor(UP), std::invalid_argument);
}

TEST_CASE("Getting the right neighbor of a position should get the expected one")
{
    MazePosition m{4, 4};
    MazePosition neighbor = m.getNeighbor(RIGHT);
    CHECK(neighbor.getRow() == 4);
    CHECK(neighbor.getColumn() == 5);
    CHECK(m.getRow() == 4);
    CHECK(m.getColumn() == 4);
}

TEST_CASE("Getting the right neighbor of right side position causes an error")
{
    MazePosition m{4, 6};
    REQUIRE_THROWS_AS(m.getNeighbor(RIGHT), std::invalid_argument);
}

TEST_CASE("Getting the down neighbor of a position should get the expected one")
{
    MazePosition m{4, 4};
    MazePosition neighbor = m.getNeighbor(DOWN);
    CHECK(neighbor.getRow() == 5);
    CHECK(neighbor.getColumn() == 4);
    CHECK(m.getRow() == 4);
    CHECK(m.getColumn() == 4);
}

TEST_CASE("Getting the down neighbor of down side position causes an error")
{
    MazePosition m{6, 4};
    REQUIRE_THROWS_AS(m.getNeighbor(DOWN), std::invalid_argument);
}

TEST_CASE("Getting the left neighbor of a position should get the expected one")
{
    MazePosition m{4, 4};
    MazePosition neighbor = m.getNeighbor(LEFT);
    CHECK(neighbor.getRow() == 4);
    CHECK(neighbor.getColumn() == 3);
    CHECK(m.getRow() == 4);
    CHECK(m.getColumn() == 4);
}

TEST_CASE("Getting the left neighbor of left side position causes an error")
{
    MazePosition m{4, 0};
    REQUIRE_THROWS_AS(m.getNeighbor(LEFT), std::invalid_argument);
}

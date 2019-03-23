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

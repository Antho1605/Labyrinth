#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "Game.h"
#endif

using namespace labyrinth;

TEST_CASE("A player should move the pathways before moving his piece")
{
    Game g{2};
    g.selectPlayerPosition(MazePosition(4, 5));
    REQUIRE_THROWS_AS(g.moveCurrentPlayer(), std::logic_error);
}

#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../MazeCard.h"
#endif

TEST_CASE( "MazeCards are constructed as expected", "[mazecard]" ) {
    using labyrinth::MazeCard;

    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN);
    MazeCard maze_card{shape, true};
    REQUIRE(maze_card.isGoingUp() == true);
    REQUIRE(maze_card.isGoingDown() == true);
    REQUIRE_FALSE(maze_card.isGoingLeft());
    REQUIRE_FALSE(maze_card.isGoingRight());
}

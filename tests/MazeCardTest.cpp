#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../model/MazeCard.h"
#include "../model/MazeCardShape.h"
#endif

using namespace labyrinth;

TEST_CASE( "I MazeCards are constructed as expected", "[mazecard]" ) {
    const MazeCardShape shape{MazeCardShape::UP | MazeCardShape::DOWN};
    const MazeCard maze_card{shape, true};
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingDown());
    CHECK(maze_card.isMovable());
    REQUIRE_FALSE(maze_card.isGoingLeft());
    REQUIRE_FALSE(maze_card.isGoingRight());
}

TEST_CASE("L MazeCards are constructed as expected"){
    const MazeCardShape shape{MazeCardShape::UP | MazeCardShape::RIGHT};
    const MazeCard maze_card{shape, true};
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingRight());
    CHECK(maze_card.isMovable());
    REQUIRE_FALSE(maze_card.isGoingLeft());
    REQUIRE_FALSE(maze_card.isGoingDown());
}


TEST_CASE("T MazeCards are constructed as expected"){
    const MazeCardShape shape{MazeCardShape::LEFT | MazeCardShape::RIGHT |
                             MazeCardShape::DOWN};
    const MazeCard maze_card{shape, true};
    CHECK(maze_card.isGoingRight());
    CHECK(maze_card.isMovable());
    CHECK(maze_card.isGoingLeft());
    CHECK(maze_card.isGoingDown());
    REQUIRE_FALSE(maze_card.isGoingUp());
}

TEST_CASE("Steady MazeCard can't be rotated"){
    MazeCardShape shape{MazeCardShape::DOWN | MazeCardShape::UP};
    MazeCard maze_card{shape, false};
    REQUIRE_THROWS_AS(maze_card.rotate(),std::logic_error);
}

TEST_CASE("The MazeCard I are fine rotated"){
    MazeCardShape shape{MazeCardShape::DOWN | MazeCardShape::UP};
    MazeCard maze_card{shape,true};
    maze_card.rotate();
    CHECK(maze_card.getShape().isGoingRight());
    CHECK(maze_card.getShape().isGoingLeft());
    REQUIRE_FALSE(maze_card.getShape().isGoingUp());
    REQUIRE_FALSE(maze_card.getShape().isGoingDown());
}








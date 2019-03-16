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

TEST_CASE("The MazeCards I are fine rotated"){
    MazeCardShape shape{MazeCardShape::DOWN | MazeCardShape::UP};
    MazeCard maze_card{shape,true};
    maze_card.rotate();
    CHECK(maze_card.getShape().isGoingRight());
    CHECK(maze_card.getShape().isGoingLeft());
    REQUIRE_FALSE(maze_card.getShape().isGoingUp());
    REQUIRE_FALSE(maze_card.getShape().isGoingDown());
}

TEST_CASE("The MazeCards L are fine rotated"){
    MazeCardShape shape{MazeCardShape::UP | MazeCardShape::RIGHT};
    MazeCard maze_card{shape,true};
    maze_card.rotate();
    CHECK(maze_card.getShape().isGoingRight());
    CHECK(maze_card.getShape().isGoingDown());
    REQUIRE_FALSE(maze_card.getShape().isGoingUp());
    REQUIRE_FALSE(maze_card.getShape().isGoingLeft());
}

TEST_CASE("The MazeCards T are fine rotated"){
    MazeCardShape shape{MazeCardShape::UP | MazeCardShape::RIGHT |
                       MazeCardShape::DOWN};
    MazeCard maze_card{shape,true};
    maze_card.rotate();
    CHECK(maze_card.getShape().isGoingDown());
    CHECK(maze_card.getShape().isGoingRight());
    CHECK(maze_card.getShape().isGoingLeft());
    REQUIRE_FALSE(maze_card.getShape().isGoingUp());
}

TEST_CASE("I MazeCard should know it is of shape I"){
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeCardShape::LEFT | MazeCardShape::RIGHT};
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < ROTATIONS; i++) {
        maze_card.rotate();
        CHECK(maze_card.isI());
        REQUIRE_FALSE(maze_card.isL());
        REQUIRE_FALSE(maze_card.isT());
    }
}

TEST_CASE("L MazeCard should know it is of shape L"){
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeCardShape::UP | MazeCardShape::RIGHT};
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < ROTATIONS; i++) {
        maze_card.rotate();
        CHECK(maze_card.isL());
        REQUIRE_FALSE(maze_card.isI());
        REQUIRE_FALSE(maze_card.isT());
    }
}

TEST_CASE("T MazeCard should know it is of shape T"){
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeCardShape::LEFT | MazeCardShape::RIGHT
                       | MazeCardShape::DOWN};
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < ROTATIONS; i++) {
        maze_card.rotate();
        CHECK(maze_card.isT());
        REQUIRE_FALSE(maze_card.isL());
        REQUIRE_FALSE(maze_card.isI());
    }
}






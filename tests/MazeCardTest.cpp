#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "MazeCard.h"
#include "MazeCardShape.h"
#endif

using namespace labyrinth::model;

TEST_CASE( "MazeCards are constructed as expected with given all values") {
    const MazeCardShape shape{MazeDirection::UP | MazeDirection::DOWN};
    const MazeCard maze_card{shape, true, Object::CROWN};
    CHECK(maze_card.isGoing(MazeDirection::UP));
    CHECK(maze_card.isGoing(MazeDirection::DOWN));
    CHECK(maze_card.isMovable());
    CHECK(maze_card.getObject() == Object::CROWN);
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::RIGHT));
}

TEST_CASE( "I MazeCards are constructed as expected with default arguments") {
    const MazeCardShape shape{MazeDirection::UP | MazeDirection::DOWN};
    const MazeCard maze_card{shape, true};
    CHECK(maze_card.isGoing(MazeDirection::UP));
    CHECK(maze_card.isGoing(MazeDirection::DOWN));
    CHECK(maze_card.isMovable());
    CHECK(maze_card.getObject() == Object::NONE);
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::RIGHT));
}

TEST_CASE("L MazeCards are constructed as expected"){
    const MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    const MazeCard maze_card{shape, true};
    CHECK(maze_card.isGoing(MazeDirection::UP));
    CHECK(maze_card.isGoing(MazeDirection::RIGHT));
    CHECK(maze_card.isMovable());
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::DOWN));
}


TEST_CASE("T MazeCards are constructed as expected"){
    const MazeCardShape shape{MazeDirection::LEFT | MazeDirection::RIGHT |
                             MazeDirection::DOWN};
    const MazeCard maze_card{shape, true};
    CHECK(maze_card.isGoing(MazeDirection::RIGHT));
    CHECK(maze_card.isMovable());
    CHECK(maze_card.isGoing(MazeDirection::LEFT));
    CHECK(maze_card.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::UP));
}

TEST_CASE("Steady MazeCard can't be rotated"){
    MazeCardShape shape{MazeDirection::DOWN | MazeDirection::UP};
    MazeCard maze_card{shape, false};
    REQUIRE_THROWS_AS(maze_card.rotate(),std::logic_error);
}

TEST_CASE("The MazeCards I are fine rotated"){
    MazeCardShape shape{MazeDirection::DOWN | MazeDirection::UP};
    MazeCard maze_card{shape,true};
    maze_card.rotate();
    CHECK(maze_card.isGoing(MazeDirection::RIGHT));
    CHECK(maze_card.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::UP));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::DOWN));
}

TEST_CASE("The MazeCards L are fine rotated"){
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    MazeCard maze_card{shape,true};
    maze_card.rotate();
    CHECK(maze_card.isGoing(MazeDirection::RIGHT));
    CHECK(maze_card.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::UP));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::LEFT));
}

TEST_CASE("The MazeCards T are fine rotated"){
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT |
                       MazeDirection::DOWN};
    MazeCard maze_card{shape,true};
    maze_card.rotate();
    CHECK(maze_card.isGoing(MazeDirection::DOWN));
    CHECK(maze_card.isGoing(MazeDirection::RIGHT));
    CHECK(maze_card.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(maze_card.isGoing(MazeDirection::UP));
}

TEST_CASE("I MazeCard should know it is of shape I"){
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeDirection::LEFT | MazeDirection::RIGHT};
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
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
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
    MazeCardShape shape{MazeDirection::LEFT | MazeDirection::RIGHT
                       | MazeDirection::DOWN};
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < ROTATIONS; i++) {
        maze_card.rotate();
        CHECK(maze_card.isT());
        REQUIRE_FALSE(maze_card.isL());
        REQUIRE_FALSE(maze_card.isI());
    }
}





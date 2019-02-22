#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../MazeCard.h"
#endif

TEST_CASE( "I MazeCards are constructed as expected", "[mazecard]" ) {
    using labyrinth::MazeCard;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN);
    MazeCard maze_card{shape, true};
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingDown());
    CHECK(maze_card.isMovable());
    REQUIRE_FALSE(maze_card.isGoingLeft());
    REQUIRE_FALSE(maze_card.isGoingRight());
}

TEST_CASE( "I MazeCards are rotable once", "[mazecard]" ) {
    using labyrinth::MazeCard;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN);
    MazeCard maze_card{shape, true};
    maze_card.rotate();
    CHECK(maze_card.isGoingLeft());
    CHECK(maze_card.isGoingRight());
    REQUIRE_FALSE(maze_card.isGoingUp());
    REQUIRE_FALSE(maze_card.isGoingDown());
}

TEST_CASE( "I MazeCards are rotable twice in a row", "[mazecard]" ) {
    using labyrinth::MazeCard;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN);
    MazeCard maze_card{shape, true};
    maze_card.rotate();
    maze_card.rotate();
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingDown());
    REQUIRE_FALSE(maze_card.isGoingRight());
    REQUIRE_FALSE(maze_card.isGoingLeft());
}

TEST_CASE( "L MazeCards are rotable once", "[mazecard]" ) {
    using labyrinth::MazeCard;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    maze_card.rotate();
    CHECK(maze_card.isGoingDown());
    CHECK(maze_card.isGoingRight());
    REQUIRE_FALSE(maze_card.isGoingUp());
    REQUIRE_FALSE(maze_card.isGoingLeft());
}

TEST_CASE( "L MazeCards are rotable twice in a row", "[mazecard]" ) {
    using labyrinth::MazeCard;
    unsigned NB_OF_ROTATION = 2;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < NB_OF_ROTATION; ++i) maze_card.rotate();
    CHECK(maze_card.isGoingDown());
    CHECK(maze_card.isGoingLeft());
    REQUIRE_FALSE(maze_card.isGoingUp());
    REQUIRE_FALSE(maze_card.isGoingRight());
}

TEST_CASE( "L MazeCards are rotable three times in a row", "[mazecard]" ) {
    using labyrinth::MazeCard;
    unsigned NB_OF_ROTATION = 3;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < NB_OF_ROTATION; ++i) maze_card.rotate();
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingLeft());
    REQUIRE_FALSE(maze_card.isGoingDown());
    REQUIRE_FALSE(maze_card.isGoingRight());
}

TEST_CASE( "L MazeCards are rotable four times in a row", "[mazecard]" ) {
    using labyrinth::MazeCard;
    unsigned NB_OF_ROTATION = 4;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < NB_OF_ROTATION; ++i) maze_card.rotate();
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingRight());
    REQUIRE_FALSE(maze_card.isGoingDown());
    REQUIRE_FALSE(maze_card.isGoingLeft());
}

TEST_CASE( "T MazeCards are rotable once", "[mazecard]" ) {
    using labyrinth::MazeCard;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    maze_card.rotate();
    CHECK(maze_card.isGoingLeft());
    CHECK(maze_card.isGoingRight());
    CHECK(maze_card.isGoingDown());
    REQUIRE_FALSE(maze_card.isGoingUp());
}

TEST_CASE( "T MazeCards are rotable twice in a row", "[mazecard]" ) {
    using labyrinth::MazeCard;
    unsigned NB_OF_ROTATION = 2;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < NB_OF_ROTATION; ++i) maze_card.rotate();
    CHECK(maze_card.isGoingLeft());
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingDown());
    REQUIRE_FALSE(maze_card.isGoingRight());
}

TEST_CASE( "T MazeCards are rotable three times in a row", "[mazecard]" ) {
    using labyrinth::MazeCard;
    unsigned NB_OF_ROTATION = 3;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < NB_OF_ROTATION; ++i) maze_card.rotate();
    CHECK(maze_card.isGoingLeft());
    CHECK(maze_card.isGoingRight());
    CHECK(maze_card.isGoingUp());
    REQUIRE_FALSE(maze_card.isGoingDown());
}

TEST_CASE( "T MazeCards are rotable four times in a row", "[mazecard]" ) {
    using labyrinth::MazeCard;
    unsigned NB_OF_ROTATION = 4;
    const MazeCard::Shape shape =
            static_cast<MazeCard::Shape>(MazeCard::UP | MazeCard::DOWN | MazeCard::RIGHT);
    MazeCard maze_card{shape, true};
    for (unsigned i = 0; i < NB_OF_ROTATION; ++i) maze_card.rotate();
    CHECK(maze_card.isGoingUp());
    CHECK(maze_card.isGoingRight());
    CHECK(maze_card.isGoingDown());
    REQUIRE_FALSE(maze_card.isGoingLeft());
}

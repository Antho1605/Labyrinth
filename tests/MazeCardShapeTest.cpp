#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "../model/MazeCardShape.h"
#endif

using namespace labyrinth;

TEST_CASE("MazeCardShape are constructed as the expected shape")
{
    MazeCardShape shape{MazeDirection::UP | MazeDirection::LEFT};
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::RIGHT));
}

TEST_CASE("MazeCardShape are constructed as expected with the minimal value")
{
    MazeCardShape shape{1};
    CHECK(shape.isGoing(MazeDirection::UP));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::RIGHT));
}

TEST_CASE("MazeCardShape are constructed as expected with the maximal value")
{
    MazeCardShape shape{14};
    REQUIRE_FALSE(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::LEFT));
    CHECK(shape.isGoing(MazeDirection::DOWN));
    CHECK(shape.isGoing(MazeDirection::RIGHT));
}

TEST_CASE("MazeCardShape cannot be constructed with a value of 0")
{
    REQUIRE_THROWS_AS(MazeCardShape(0), std::invalid_argument);
}

TEST_CASE("MazeCardShape cannot be constructed with a value greater than 14")
{
    REQUIRE_THROWS_AS(MazeCardShape(15), std::invalid_argument);
}

TEST_CASE("T MazeCardShape should know it is of T shape")
{
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::LEFT
                | MazeDirection::DOWN};
    for (unsigned i = 0; i < ROTATIONS; i++){
        shape.rotate();
        CHECK(shape.isT());
        REQUIRE_FALSE(shape.isL());
        REQUIRE_FALSE(shape.isI());
    }
}

TEST_CASE("L MazeCardShape should know it is of L shape")
{
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    for (unsigned i = 0; i < ROTATIONS; i++){
        shape.rotate();
        CHECK(shape.isL());
        REQUIRE_FALSE(shape.isT());
        REQUIRE_FALSE(shape.isI());
    }
}

TEST_CASE("I MazeCardShape should know it is of I shape")
{
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeDirection::LEFT | MazeDirection::RIGHT};
    for (unsigned i = 0; i < ROTATIONS; i++) {
        shape.rotate();
        CHECK(shape.isI());
        REQUIRE_FALSE(shape.isL());
        REQUIRE_FALSE(shape.isT());
    }
}

TEST_CASE( "Vertical I MazeCardShape are rotable once") {
    MazeCardShape shape{MazeDirection::UP | MazeDirection::DOWN};
    shape.rotate();
    CHECK(shape.isGoing(MazeDirection::LEFT));
    CHECK(shape.isGoing(MazeDirection::RIGHT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::UP));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::DOWN));
    CHECK(shape.isI());
}

TEST_CASE( "Horizontal I MazeCardShape are rotable once") {
    MazeCardShape shape{MazeDirection::LEFT | MazeDirection::RIGHT};
    shape.rotate();
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::RIGHT));
    CHECK(shape.isI());
}

TEST_CASE( "I MazeCardShape are rotable twice in a row") {
    const unsigned ROTATIONS = 2;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::DOWN};
    for (unsigned i = 0; i < ROTATIONS; i++) shape.rotate();
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::RIGHT));
}

TEST_CASE( "L MazeCardShape are rotable once") {
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    shape.rotate();
    CHECK(shape.isGoing(MazeDirection::DOWN));
    CHECK(shape.isGoing(MazeDirection::RIGHT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::UP));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::LEFT));
}

TEST_CASE( "L MazeCardShape are rotable twice in a row") {
    const unsigned ROTATIONS = 2;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    for (unsigned i = 0; i < ROTATIONS; i++) shape.rotate();
    CHECK(shape.isGoing(MazeDirection::LEFT));
    CHECK(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::UP));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::RIGHT));
}

TEST_CASE( "L MazeCardShape are rotable three times in a row") {
    const unsigned ROTATIONS = 3;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    for (unsigned i = 0; i < ROTATIONS; i++) shape.rotate();
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::RIGHT));
}

TEST_CASE( "L MazeCardShape are rotable four times in a row") {
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT};
    for (unsigned i = 0; i < ROTATIONS; i++) shape.rotate();
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::RIGHT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::LEFT));
}

TEST_CASE( "T MazeCardShape are rotable once") {
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT | MazeDirection::DOWN};
    shape.rotate();
    CHECK(shape.isGoing(MazeDirection::DOWN));
    CHECK(shape.isGoing(MazeDirection::RIGHT));
    CHECK(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::UP));
}

TEST_CASE( "T MazeCardShape are rotable twice in a row") {
    const unsigned ROTATIONS = 2;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT | MazeDirection::DOWN};
    for (unsigned i = 0; i < ROTATIONS; i++) shape.rotate();
    CHECK(shape.isGoing(MazeDirection::DOWN));
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::RIGHT));
}

TEST_CASE( "T MazeCardShape are rotable three times in a row") {
    const unsigned ROTATIONS = 3;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT | MazeDirection::DOWN};
    for (unsigned i = 0; i < ROTATIONS; i++) shape.rotate();
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::RIGHT));
    CHECK(shape.isGoing(MazeDirection::LEFT));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::DOWN));
}

TEST_CASE( "T MazeCardShape are rotable four times in a row") {
    const unsigned ROTATIONS = 4;
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT | MazeDirection::DOWN};
    for (unsigned i = 0; i < ROTATIONS; i++) shape.rotate();
    CHECK(shape.isGoing(MazeDirection::UP));
    CHECK(shape.isGoing(MazeDirection::RIGHT));
    CHECK(shape.isGoing(MazeDirection::DOWN));
    REQUIRE_FALSE(shape.isGoing(MazeDirection::LEFT));
}

TEST_CASE("Test of the getShape method"){
    MazeCardShape shape{MazeDirection::UP | MazeDirection::RIGHT | MazeDirection::DOWN};
    CHECK(shape.getValue() == 7);
}

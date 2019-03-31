#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "MazePosition.h"
#include "Player.h"
#include "ObjectivesDeck.h"
#include <stdexcept>
#include <vector>
#endif

using namespace labyrinth;

TEST_CASE("A player is constructed as expected")
{
    Player p{Player::Color::BLUE};
    CHECK(p.getColor() == Player::Color::BLUE);
    CHECK(p.getPosition().getRow() == 0);
    CHECK(p.getPosition().getColumn() == 0);
    CHECK(p.getState() == Player::State::WAITING);
}

TEST_CASE("Setting a player position moves the player at the expected position")
{
    const unsigned NEW_ROW = 4;
    const unsigned NEW_COLUMN = 3;
    Player p{Player::Color::BLUE};
    p.moveTo(NEW_ROW, NEW_COLUMN);
    CHECK(p.getPosition().getRow() == NEW_ROW);
    CHECK(p.getPosition().getColumn() == NEW_COLUMN);
}

TEST_CASE("Setting an invalid position causes an exception")
{
    const unsigned NEW_ROW = 7;
    const unsigned NEW_COLUMN = 12;
    Player p{Player::Color::BLUE};
    REQUIRE_THROWS_AS(p.moveTo(NEW_ROW, NEW_COLUMN), std::logic_error);
}

TEST_CASE("Turning the current objective card over.")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE};
    p.setObjectives(d);
    p.turnCurrentObjectiveOver();
    CHECK(p.getCurrentObjective()->isTurnedOver());
}

TEST_CASE("Turning all the objectives of a player")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE};
    p.setObjectives(d);
    for (unsigned i = 0; i < 5; ++i) {
        p.turnCurrentObjectiveOver();
        p.nextObjective();
    }
    p.turnCurrentObjectiveOver();
    CHECK(p.hasFoundAllObjectives());
}

TEST_CASE("nextObjective passes to the next objective that is not turned over")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE};
    p.setObjectives(d);
    for (unsigned i = 0; i < 4; ++i) {
        p.turnCurrentObjectiveOver();
        p.nextObjective();
    }
    CHECK(p.getCurrentObjective()->getObject() == Object::KEYS);
}

TEST_CASE("If all objectives are found, nextObjective causes an exception on call")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE};
    p.setObjectives(d);
    for (unsigned i = 0; i < 5; ++i) {
        p.turnCurrentObjectiveOver();
        p.nextObjective();
    }
    p.turnCurrentObjectiveOver();
    REQUIRE_THROWS_AS(p.nextObjective(), std::logic_error);
}

TEST_CASE("A player can be copied")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE};
    p.setObjectives(d);
    Player p0{p};
    CHECK(p0 == p);
}

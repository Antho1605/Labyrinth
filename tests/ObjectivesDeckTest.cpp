#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "ObjectivesDeck.h"
#include <vector>
#include <iostream>
#endif

using namespace labyrinth::model;

TEST_CASE("The current card is the first one in an untouched deck.")
{
    ObjectivesDeck d{
        Object::BAT,
        Object::DRAGON,
        Object::EMERALD,
        Object::FAIRY,
        Object::KEYS,
        Object::GHOST
    };
    CHECK(d.getCurrentCard().getObject() == Object::BAT);
}

TEST_CASE("The current card is the second one if the first is turned over")
{
    ObjectivesDeck d{
        Object::BAT,
        Object::DRAGON,
        Object::EMERALD,
        Object::FAIRY,
        Object::KEYS,
        Object::GHOST
    };
    d.getCurrentCard().turnOver();
    CHECK(d.getCurrentCard().getObject() == Object::DRAGON);
}

TEST_CASE("If only one card is not turned oved, it should be the current card")
{
    const unsigned TURNED_OVER_CARDS{5};
    ObjectivesDeck d{
        Object::BAT,
        Object::DRAGON,
        Object::EMERALD,
        Object::FAIRY,
        Object::KEYS,
        Object::GHOST
    };
    for (unsigned i = 0; i < TURNED_OVER_CARDS; ++i) {
        d.getCurrentCard().turnOver();
    }
    CHECK(d.getCurrentCard().getObject() == Object::GHOST);
}


TEST_CASE("If all the cards have been turned over, the current card is nullptr")
{
    const unsigned TURNED_OVER_CARDS{6};
    ObjectivesDeck d{
        Object::BAT,
        Object::DRAGON,
        Object::EMERALD,
        Object::FAIRY,
        Object::KEYS,
        Object::GHOST
    };
    for (unsigned i = 0; i < TURNED_OVER_CARDS; ++i) {
        d.getCurrentCard().turnOver();
    }
    REQUIRE_THROWS_AS(d.getCurrentCard(), std::logic_error);
}

TEST_CASE("Only a part of the cards are turned over")
{
    const unsigned TURNED_OVER_CARDS{3};
    ObjectivesDeck d{
        Object::BAT,
        Object::DRAGON,
        Object::EMERALD,
        Object::FAIRY,
        Object::KEYS,
        Object::GHOST
    };
    for (unsigned i = 0; i < TURNED_OVER_CARDS; ++i) {
        d.getCurrentCard().turnOver();
    }
    REQUIRE_FALSE(d.areAllCardsTurnedOver());
}


TEST_CASE("All the cards should be turned over after turning them over")
{
    const unsigned TURNED_OVER_CARDS{6};
    ObjectivesDeck d{
        Object::BAT,
        Object::DRAGON,
        Object::EMERALD,
        Object::FAIRY,
        Object::KEYS,
        Object::GHOST
    };
    for (unsigned i = 0; i < TURNED_OVER_CARDS; ++i) {
        d.getCurrentCard().turnOver();
    }
    CHECK(d.areAllCardsTurnedOver());
}



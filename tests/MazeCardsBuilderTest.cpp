#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../model/MazeCardsBuilder.h"
#include <vector>
#endif

using namespace labyrinth;

TEST_CASE("Steady cards are constructed as expected.")
{
    MazeCardsBuilder builder;
    std::vector<MazeCard> cards;
    builder.getSteadyCards(cards);
    for (auto const &card : cards) CHECK(!card.isMovable());
    CHECK(cards.size() == 16);
}

TEST_CASE("Movable cards are constructed as expected.")
{
    MazeCardsBuilder builder;
    std::vector<MazeCard> cards;
    builder.getMovableCards(cards);
    for (auto const &card : cards) CHECK(card.isMovable());
    CHECK(cards.size() == 34);
}

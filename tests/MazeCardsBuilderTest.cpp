#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "MazeCardsBuilder.h"
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

TEST_CASE("The exepcted number of movable T cards is constructed")
{
    MazeCardsBuilder builder;
    std::vector<MazeCard> cards;
    builder.constructMarkedTCards(cards);
    for (auto const &card : cards) {
        CHECK(card.isMovable());
        CHECK(card.isMarked());
    }
    CHECK(cards.size() == 6);
}

TEST_CASE("The exepcted number of movable I cards is constructed")
{
    MazeCardsBuilder builder;
    std::vector<MazeCard> cards;
    builder.constructICards(cards);
    for (auto const &card : cards) CHECK(card.isMovable());
    CHECK(cards.size() == 12);
}

TEST_CASE("The exepcted number of movable L cards is constructed")
{
    MazeCardsBuilder builder;
    std::vector<MazeCard> cards;
    builder.constructLCards(cards);
    for (auto const &card : cards) CHECK(card.isMovable());
    CHECK(cards.size() == 10);
}

TEST_CASE("The exepcted number of marked movable L cards is constructed")
{
    MazeCardsBuilder builder;
    std::vector<MazeCard> cards;
    builder.constructMarkedLCards(cards);
    for (auto const &card : cards) {
        CHECK(card.isMovable());
        CHECK(card.isMarked());
    }
    CHECK(cards.size() == 6);
}

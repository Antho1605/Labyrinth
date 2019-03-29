#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "Game.h"
#endif

using namespace labyrinth;

TEST_CASE("The game is constructed as expected with 2 players")
{
    Game g{2};
    for (auto player : g.getPlayers()) {
        CHECK(player.getObjectives().getCards().size() == 12);
    }
    CHECK(g.getPlayers().at(0).getColor() == Player::Color::RED);
    CHECK(g.getPlayers().at(1).getColor() == Player::Color::BLUE);
    CHECK(g.getPlayers().at(0).getColor() == g.getCurrentPlayer().getColor());
    CHECK(g.getPlayers().size() == 2);
}

TEST_CASE("The game is constructed as expected with 3 players")
{
    Game g{3};
    for (auto player : g.getPlayers()) {
        CHECK(player.getObjectives().getCards().size() == 8);
    }
    CHECK(g.getPlayers().at(0).getColor() == Player::Color::RED);
    CHECK(g.getPlayers().at(1).getColor() == Player::Color::BLUE);
    CHECK(g.getPlayers().at(2).getColor() == Player::Color::YELLOW);
    CHECK(g.getPlayers().at(0).getColor() == g.getCurrentPlayer().getColor());
    CHECK(g.getPlayers().size() == 3);
}

TEST_CASE("The game is constructed as expected with 4 players")
{
    Game g{4};
    for (auto player : g.getPlayers()) {
        CHECK(player.getObjectives().getCards().size() == 6);
    }
    CHECK(g.getPlayers().at(0).getColor() == Player::Color::RED);
    CHECK(g.getPlayers().at(1).getColor() == Player::Color::BLUE);
    CHECK(g.getPlayers().at(2).getColor() == Player::Color::YELLOW);
    CHECK(g.getPlayers().at(3).getColor() == Player::Color::GREEN);
    CHECK(g.getPlayers().at(0).getColor() == g.getCurrentPlayer().getColor());
    CHECK(g.getPlayers().size() == 4);
}

TEST_CASE("Construct a game with one player causes an error")
{
    REQUIRE_THROWS_AS(Game{1}, std::logic_error);
}

TEST_CASE("Construct a game with five players causes an error")
{
    REQUIRE_THROWS_AS(Game{5}, std::logic_error);
}




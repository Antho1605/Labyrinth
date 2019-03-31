#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "Game.h"
#endif

using namespace labyrinth;

TEST_CASE("A player should move the pathways before moving his piece")
{
    Game g{2};
    g.selectPlayerPosition(MazePosition(4, 5));
    REQUIRE_THROWS_AS(g.moveCurrentPlayer(), std::logic_error);
}

TEST_CASE("Selecting a player position should select the expected position")
{
    Game g{2};
    g.selectPlayerPosition({4, 2});
    CHECK(g.getSelectedPlayerPosition() == MazePosition{4, 2});
}

TEST_CASE("Selecting an insertion position should select the expected position")
{
    Game g{2};
    g.selectInsertionPosition({1, 0});
    CHECK(g.getSelectedInsertionPosition() == MazePosition{1, 0});
}

TEST_CASE("The current player inserts in the maze without errors")
{
    Game g{2};
    MazePosition insertion{1, 0};
    MazeCard inserted = g.getCurrentMazeCard();
    MazeCard ejected = g.getMaze().getCardAt({1, 6});
    g.selectInsertionPosition(insertion);
    g.movePathWays();
    CHECK(g.getMaze().getCardAt(insertion) == inserted);
    CHECK(g.getCurrentMazeCard() == ejected);
    CHECK(g.getCurrentPlayer().hasMovedPathWays());
}

TEST_CASE("Selecting a insertion position that is not inserrable causes an error")
{
    Game g{2};
    REQUIRE_THROWS_AS(g.selectInsertionPosition(MazePosition(4, 5)),
                      std::logic_error);
}

TEST_CASE("The current players plays an entire turn without errors")
{
    Game g{2};
    MazePosition insertion{1, 0};
    MazePosition player{g.getCurrentPlayer().getPosition()};
    MazeCard inserted = g.getCurrentMazeCard();
    MazeCard ejected = g.getMaze().getCardAt({1, 6});
    g.selectInsertionPosition(insertion);
    g.movePathWays();
    CHECK(g.getMaze().getCardAt(insertion) == inserted);
    CHECK(g.getCurrentMazeCard() == ejected);
    CHECK(g.getCurrentPlayer().hasMovedPathWays());
    g.selectPlayerPosition(player);
    g.moveCurrentPlayer();
    CHECK(g.getCurrentPlayer().getPosition() == player);
    CHECK(g.getCurrentPlayer().hasMoved());
}

TEST_CASE("The game passes to the next player as expected with 2 players") {
    Game g{2};
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::BLUE);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
}

TEST_CASE("The game passes to the next player as expected with 3 players") {
    Game g{3};
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::BLUE);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::YELLOW);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
}

TEST_CASE("The game passes to the next player as expected with 4 players") {
    Game g{4};
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::BLUE);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::YELLOW);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::GREEN);
    g.getCurrentPlayer().setState(Player::State::MOVED_PIECE);
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
}


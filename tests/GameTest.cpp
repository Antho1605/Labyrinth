#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "Game.h"
#endif

using namespace labyrinth::model;

TEST_CASE("A player should move the pathways before moving his piece")
{
    Game g{2};
    g.selectPlayerPosition(g.getCurrentPlayer().getPosition());
    REQUIRE_THROWS_AS(g.moveCurrentPlayer(), std::logic_error);
}

TEST_CASE("Selecting a player position should select the expected position")
{
    Game g{2};
    g.selectPlayerPosition(g.getCurrentPlayer().getPosition());
    CHECK(g.getSelectedPlayerPosition() == MazePosition{0, 0});
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
    CHECK(g.getCurrentPlayer().isReadyToMove());
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
    CHECK(g.getCurrentPlayer().isReadyToMove());
    g.selectPlayerPosition(player);
    g.moveCurrentPlayer();
    CHECK(g.getCurrentPlayer().getPosition() == player);
    CHECK(g.getCurrentPlayer().isDone());
}

TEST_CASE("The game passes to the next player as expected with 2 players") {
    Game g{2};
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::BLUE);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
}

TEST_CASE("The game passes to the next player as expected with 3 players") {
    Game g{3};
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::BLUE);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::YELLOW);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
}

TEST_CASE("The game passes to the next player as expected with 4 players") {
    Game g{4};
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::BLUE);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::YELLOW);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::GREEN);
    g.getCurrentPlayer().setReadyToMove();
    g.getCurrentPlayer().setDone();
    g.nextPlayer();
    CHECK(g.getCurrentPlayer().getColor() == Player::RED);
}



TEST_CASE("A game is over when if the first player is the winner")
{
    Game g{2};
    g.getCurrentPlayer().turnAllObjectivesOver();
    CHECK(g.isOver());
    CHECK(g.getCurrentPlayer() == g.getWinner());
}

TEST_CASE("A game is not over when it has no winner")
{
    Game g{};
    REQUIRE_FALSE(g.isOver());
}

TEST_CASE("The player should not be able to movePathWays two times in a row"
          "even after selecting 2 times."){
    Game game{};
    game.selectInsertionPosition(MazePosition{0,1});
    game.movePathWays();
    game.selectInsertionPosition(MazePosition{1,0});
    REQUIRE_THROWS(game.movePathWays());
}

TEST_CASE("The current maze card should be the last pushed out mazecard after"
          "movePathWays"){
    Game game{};
    game.selectInsertionPosition(MazePosition{0,1});
    MazeCard pushedOut = game.getMaze().getCardAt(MazePosition{6,1});
    game.movePathWays();
    CHECK(pushedOut == game.getCurrentMazeCard());
}

TEST_CASE("A simplified game is over when if the first player is the winner")
{
    Game g{2, true};
    g.getCurrentPlayer().setPosition({2, 3});
    g.getCurrentPlayer().turnAllObjectivesOver();
    CHECK(g.isOver());
    CHECK(g.getCurrentPlayer() == g.getWinner());
}

TEST_CASE("A game is not over when it has no winner")
{
    Game g{};
    REQUIRE_FALSE(g.isOver());
}

TEST_CASE("A simplfied game is not over when it has no winner")
{
    Game g{2, true};
    REQUIRE_FALSE(g.isOver());
}

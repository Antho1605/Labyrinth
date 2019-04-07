#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "Game.h"
#endif

using namespace labyrinth::model;

TEST_CASE("When inserting a card the player on the same column should be moved"){
    Game game{};
    MazePosition expectedPlayerPosition{1,1};
    game.selectInsertionPosition(MazePosition{0,1});
    game.getCurrentPlayer().setPosition(MazePosition{0,1});
    game.movePathWays();
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

TEST_CASE("When inserting a card the player on the same row should be moved."){
    Game game{};
    MazePosition expectedPlayerPosition{1,1};
    game.selectInsertionPosition(MazePosition{1,0});
    game.getCurrentPlayer().setPosition(MazePosition{1,0});
    game.movePathWays();
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

TEST_CASE("The player should be moved to the down side when ejected on the "
          "up side"){
    Game game{};
    MazePosition expectedPlayerPosition{6,1};
    game.selectInsertionPosition(MazePosition{6,1});
    game.getCurrentPlayer().setPosition(MazePosition{0,1});
    game.movePathWays();
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

TEST_CASE("The player should be moved to the up side when ejected on the "
          "down side"){
    Game game{};
    MazePosition expectedPlayerPosition{0,1};
    game.selectInsertionPosition(MazePosition{0,1});
    game.getCurrentPlayer().setPosition(MazePosition{6,1});
    game.movePathWays();
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

TEST_CASE("The player should be moved to the left side when ejected on the "
          "right side"){
    Game game{};
    MazePosition expectedPlayerPosition{1,0};
    game.selectInsertionPosition(MazePosition{1,0});
    game.getCurrentPlayer().setPosition(MazePosition{1,6});
    game.movePathWays();
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

TEST_CASE("The player should be moved to the right side when ejected on the "
          "left side"){
    Game game{};
    MazePosition expectedPlayerPosition{1,6};
    game.selectInsertionPosition(MazePosition{1,6});
    game.getCurrentPlayer().setPosition(MazePosition{1,0});
    game.movePathWays();
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}


TEST_CASE("When inserting a card two player on the same row should be moved."){
    Game game{};
    MazePosition expectedPlayerPosition{1,1};
    game.selectInsertionPosition(MazePosition{3,0});
    game.getCurrentPlayer().setPosition(MazePosition{1,0});
    game.movePathWays();
    game.getCurrentPlayer().setDone();
    game.nextPlayer();
    game.getCurrentPlayer().setPosition(MazePosition{1,0});
    game.selectInsertionPosition(MazePosition{1,0});
    game.movePathWays();
    CHECK(game.getPlayers().at(0).getPosition() == expectedPlayerPosition);
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

TEST_CASE("When inserting a card two player on the same column should be moved."){
    Game game{};
    MazePosition expectedPlayerPosition{1,1};
    game.selectInsertionPosition(MazePosition{3,0});
    game.getCurrentPlayer().setPosition(MazePosition{0,1});
    game.movePathWays();
    game.getCurrentPlayer().setDone();
    game.nextPlayer();
    game.getCurrentPlayer().setPosition(MazePosition{0,1});
    game.selectInsertionPosition(MazePosition{0,1});
    game.movePathWays();
    CHECK(game.getPlayers().at(0).getPosition() == expectedPlayerPosition);
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

TEST_CASE("When two players are ejected they should be moved at the opposite "
          "of the maze."){
    Game game{};
    MazePosition expectedPlayerPosition{1,0};
    game.selectInsertionPosition(MazePosition{3,0});
    game.getCurrentPlayer().setPosition(MazePosition{1,6});
    game.movePathWays();
    game.getCurrentPlayer().setDone();
    game.nextPlayer();
    game.getCurrentPlayer().setPosition(MazePosition{1,6});
    game.selectInsertionPosition(MazePosition{1,0});
    game.movePathWays();
    CHECK(game.getPlayers().at(0).getPosition() == expectedPlayerPosition);
    CHECK(game.getCurrentPlayer().getPosition() == expectedPlayerPosition);
}

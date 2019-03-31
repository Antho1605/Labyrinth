#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include <stdexcept>
#include "Maze.h"
#endif

using namespace labyrinth;

TEST_CASE("Two maze cards linked by a direct path should be neigbors")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | DOWN, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    CHECK(m.existDirectPathBetween(a, b));
}

TEST_CASE("Two maze cards that are not directly linked should not be neighbors")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | RIGHT, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_FALSE(m.existDirectPathBetween(a, b));
}

TEST_CASE("existDirectPathBetween throws an exception if the first position is invalid")
{
    Maze m;
    MazePosition b{4, 4};
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_THROWS_AS(m.existDirectPathBetween(MazePosition{6, 8}, b), std::logic_error);
}

TEST_CASE("existDirectPathBetween throws an exception if the second position is invalid")
{
    Maze m;
    MazePosition a{0, 0};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | RIGHT, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    REQUIRE_THROWS_AS(m.existDirectPathBetween(a, b), std::logic_error);
}

TEST_CASE("Two adjacent maze cards are adjacent after adjacency update")
{
    Maze m;
    MazePosition a{3, 4};
    MazePosition b{4, 4};
    m.setCardAt(a, MazeCard{LEFT | DOWN, true});
    m.setCardAt(b, MazeCard{UP | DOWN, true});
    m.updateAdjacency();
    CHECK(m.areAdjacent(a, b));
}

TEST_CASE("Adjacencies are initialized as expected after maze construction")
{
    Maze m;
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            MazePosition position{row, column};
            for (MazeDirection direction = UP; direction <= LEFT; ++direction) {
                if (position.hasNeighbor(direction)) {
                    MazePosition neighbor = position.getNeighbor(direction);
                    if (m.existDirectPathBetween(position, neighbor))
                        CHECK(m.areAdjacent(position, neighbor));
                }
            }
        }
    }
}

TEST_CASE("Adjacencies are updated after insertion in upper side.")
{
    Maze m;
    m.insertLastPushedOutMazeCardAt(MazePosition{0, 1});
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            MazePosition position{row, column};
            for (MazeDirection direction = UP; direction <= LEFT; ++direction) {
                if (position.hasNeighbor(direction)) {
                    MazePosition neighbor = position.getNeighbor(direction);
                    if (m.existDirectPathBetween(position, neighbor))
                        CHECK(m.areAdjacent(position, neighbor));
                }
            }
        }
    }
}

TEST_CASE("Adjacencies are updated after insertion in left side.")
{
    Maze m;
    m.insertLastPushedOutMazeCardAt(MazePosition{3, 0});
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            MazePosition position{row, column};
            for (MazeDirection direction = UP; direction <= LEFT; ++direction) {
                if (position.hasNeighbor(direction)) {
                    MazePosition neighbor = position.getNeighbor(direction);
                    if (m.existDirectPathBetween(position, neighbor))
                        CHECK(m.areAdjacent(position, neighbor));
                }
            }
        }
    }
}

TEST_CASE("Adjacencies are updated after insertion in right side.")
{
    Maze m;
    m.insertLastPushedOutMazeCardAt(MazePosition{3, 6});
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            MazePosition position{row, column};
            for (MazeDirection direction = UP; direction <= LEFT; ++direction) {
                if (position.hasNeighbor(direction)) {
                    MazePosition neighbor = position.getNeighbor(direction);
                    if (m.existDirectPathBetween(position, neighbor))
                        CHECK(m.areAdjacent(position, neighbor));
                }
            }
        }
    }
}

TEST_CASE("Adjacencies are updated after insertion in down side.")
{
    Maze m;
    m.insertLastPushedOutMazeCardAt(MazePosition{6, 3});
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            MazePosition position{row, column};
            for (MazeDirection direction = UP; direction <= LEFT; ++direction) {
                if (position.hasNeighbor(direction)) {
                    MazePosition neighbor = position.getNeighbor(direction);
                    if (m.existDirectPathBetween(position, neighbor))
                        CHECK(m.areAdjacent(position, neighbor));
                }
            }
        }
    }
}

TEST_CASE("If no insertion took place, the maze adjacencies does not update")
{

}

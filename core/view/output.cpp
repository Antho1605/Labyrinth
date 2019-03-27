#include "output.h"

#include "Output.h"
#include "Game.h"
#include "Maze.h"
#include "MazePosition.h"

using namespace labyrinth::view;
using namespace labyrinth;

static char VOID = ' ';
static char HWALL = '-';
static char VWALL = '|';
static char CORNER = '+';

/**
 * For instance a T would be printed like
 *
 *  + - + <-- part 0
 *        <-- part 1
 *  +   + <-- part 2
 */
void Output::printMazeCardPart(const MazeCard &card, unsigned part)
{
    if (part == 0) {
        out_ << CORNER << (card.isGoing(UP) ? VOID : HWALL) << CORNER;
    } else if (part == 1) {
        out_ << (card.isGoing(LEFT) ? VOID : VWALL) << VOID;
        out_ << (card.isGoing(RIGHT) ? VOID : VWALL);
    } else {
        out_ << CORNER << (card.isGoing(DOWN) ? VOID : HWALL) << CORNER;
    }
}

void Output::printMazeCardPartsRow(unsigned mazeRow, unsigned part)
{
    for (unsigned mazeColumn = 0; mazeColumn < Maze::SIZE; ++mazeColumn) {
        MazeCard card = game_.getMaze().getCardAt(MazePosition{mazeRow, mazeColumn});
        printMazeCardPart(card, part);
    }
    out_ << std::endl;
}

void Output::printMaze()
{
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned part = 0; part < 3; ++part) {
            printMazeCardPartsRow(row, part);
        }
    }
}

void Output::printPlayers() const
{

}

void Output::printLastPushedOutMazeCard() const
{

}

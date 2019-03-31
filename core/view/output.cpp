#include "output.h"

#include "Output.h"
#include "Game.h"
#include "Maze.h"
#include "MazePosition.h"
#include "toString.h"

#include <string>
#include <vector>

using namespace labyrinth::view;
using namespace labyrinth;

static std::string VOID = "   ";
static std::string HWALL = "---";
static std::string VWALL = " | ";
static std::string CORNER = " + ";

void Output::print(std::string msg) const { out_ << msg << std::endl; }

void Output::printTitle() const
{
    out_ << "[DEV4] Assignment submitted by Anthony and Logan Farci (2018-2019)\n\n";
    out_ << "*************** WELCOME TO LABYRINTH ***************\n";
    out_ << "type 'help' to print the list available commands...\n\n";
}

void Output::printHelp() const
{
    out_ << "help" << VOID << "prints help command." << std::endl;
    out_ << "move <row> <column>" << VOID << "moves the player to the given position." << std::endl;
    out_ << "exit" << VOID << "exits the game." << std::endl;
}

void Output::printUpperInsertionIcons() const
{
    out_ << "    ";
    for (unsigned column = 1; column <= Maze::SIZE; ++column)
        out_ << VOID << " " << (column % 2 == 0 ? "v" : " ") << " "<< VOID;
    out_ << std::endl;
}

void Output::printDownInsertionIcons() const
{
    out_ << "    ";
    for (unsigned column = 1; column <= Maze::SIZE; ++column)
        out_ << VOID << " " << (column % 2 == 0 ? "^" : " ") << " "<< VOID;
    out_ << std::endl;
}

void Output::printColumnCoordinate() const
{
    out_ << "    ";
    for (unsigned column = 1; column <= Maze::SIZE; ++column)
        out_ << VOID << " " << column << " "<< VOID;
    out_ << std::endl;
}

void Output::printMazeCardPart(const MazeCard &card, unsigned part) const
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

void Output::printMazeCardPartsRow(unsigned mazeRow, unsigned part) const
{
    for (unsigned mazeColumn = 0; mazeColumn < Maze::SIZE; ++mazeColumn) {
        MazeCard card = game_.getMaze().getCardAt(MazePosition{mazeRow, mazeColumn});
        printMazeCardPart(card, part);
    }
}

void Output::printMaze() const
{
    printUpperInsertionIcons();
    printColumnCoordinate();
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned part = 0; part < 3; ++part) {
            if (part == 1) {
                out_ << (row % 2 != 0 ? "> " : "  ");
                out_  << (row + 1) << " ";
            } else {
                out_ << "    ";
            }
            printMazeCardPartsRow(row, part);
            if (part == 1) out_ << (row % 2 != 0 ? " <\n" : "\n");
            else out_ << "\n";
        }
    }
    printDownInsertionIcons();
}

void Output::printPlayers() const
{
    vector<Player> players = game_.getPlayers();
    for (unsigned player = 0; player < players.size(); ++player) {
        out_ << toString(players.at(player)) << endl;
    }
}

void Output::printMazeObjectives() const
{
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            MazeCard card = game_.getMaze().getCardAt(MazePosition{row, column});
            if (card.isMarked()) {
                out_ << toString(card.getObject()) + " at position ";
                print("(" + to_string(row) + "; " + to_string(column) + ").");
            }
        }
    }
}

void Output::printCurrentPlayerObjective() const
{
    Object o = game_.getCurrentPlayer().getCurrentObjective()->getObject();
    print(toString(o));
}

void Output::printCurrentMazeCard() const
{
    for (unsigned part = 0; part < 3; ++part) {
        printMazeCardPart(game_.getCurrentMazeCard(), part);
        out_ << "\n";
    }
}

#include "Output.h"
#include "Game.h"
#include "Maze.h"
#include "MazePosition.h"
#include "ToString.h"

#include <iomanip>
#include <string>
#include <vector>

using namespace labyrinth::view;
using namespace labyrinth::model;

static std::string VOID = "   ";
static std::string HWALL = "---";
static std::string VWALL = "|";
static std::string CORNER = "+";

void Output::print(std::string msg) const { out_ << msg << std::endl; }

void Output::printTitle() const
{
    out_ << "[DEV4] Assignment submitted by Anthony and Logan Farci (2018-2019)\n\n";
    out_ << "*************** WELCOME TO LABYRINTH ***************\n\n";
    out_ << "Here is the list of available commands... During the game just type 'help' to print it! \n\n";
    out_ << "\n Have fun!\n\n";
}

void Output::printPrompt() const
{
    Player::Color currentPlayerColor = game_->getCurrentPlayer().getColor();
    out_ << toString(currentPlayerColor) << " > ";
}

void Output::printHelp() const
{
    out_ << left << setw(30) << "command" << setw(50) << "description" << endl;
    out_ << setfill('-') << setw(80) << "-" << endl;
    out_ << setfill(' ');
    out_ << setw(30) << "help" << setw(50) << "prints help command." << endl;
    out_ << setw(30) <<"move <row> <column>" << setw(50) << "moves the player to the given position." << endl;
    out_ << setw(30) << "pass" << setw(50) << "pass the current player move." << std::endl;
    out_ << setw(30) <<"insert <row> <column>" << setw(50) << "inserts the current maze card at the given position." << endl;
    out_ << setw(30) << "rotate <n>" << setw(50) << "rotates the maze card n times." << endl;
    out_ << setw(30) << "show players" << setw(50) << "shows the list of the players of the game." << endl;
    out_ << setw(30) << "show mazecard" << setw(50) << "shows the current maze card (to one about to be inserted)." << endl;
    out_ << setw(30) << "show objectives" << setw(50) << "shows the list of objectives and their positions in the maze." << endl;
    out_ << setw(30) << "show objective" << setw(50) << "shows the current objective." << endl;
    out_ << setw(30) <<"exit" << setw(50)<< "exits the game." << std::endl;
}

void Output::printUpperInsertionIcons() const
{
    out_ << "    ";
    for (unsigned column = 1; column <= Maze::SIZE; ++column)
        out_ << "  " << (column % 2 == 0 ? "v" : " ") << "  ";
    out_ << std::endl;
}

void Output::printDownInsertionIcons() const
{
    out_ << "    ";
    for (unsigned column = 1; column <= Maze::SIZE; ++column)
        out_ << "  " << (column % 2 == 0 ? "^" : " ") << "  ";
    out_ << std::endl;
}

void Output::printColumnCoordinate() const
{
    out_ << "    ";
    for (unsigned column = 0; column < Maze::SIZE; ++column)
        out_ << "  " << column << "  ";
    out_ << std::endl;
}

void Output::printMazeCardPart(const MazeCard &card, unsigned part,
                               std::string icon = VOID) const
{
    if (part == 0) {
        out_ << CORNER << (card.isGoing(UP) ? VOID : HWALL) << CORNER;
    } else if (part == 1) {
        out_ << (card.isGoing(LEFT) ? " " : VWALL) << icon;
        out_ << (card.isGoing(RIGHT) ? " " : VWALL);
    } else {
        out_ << CORNER << (card.isGoing(DOWN) ? VOID : HWALL) << CORNER;
    }
}

static string getPlayersIcons(vector<Player> players) {
    stringstream icons;
    switch (players.size()) {
    case 1:
        icons << " " << toIcon(players.at(0).getColor()) << " ";
        break;
    case 2:
        icons << toIcon(players.at(0).getColor()) << " ";
        icons << toIcon(players.at(1).getColor());
        break;
    case 3:
        icons << toIcon(players.at(0).getColor());
        icons << toIcon(players.at(1).getColor());
        icons << toIcon(players.at(1).getColor());
        break;
    default:
        icons << " X ";
    }
    return icons.str();
}

void Output::printMazeCardPartsRow(unsigned mazeRow, unsigned part) const
{
    for (unsigned mazeColumn = 0; mazeColumn < Maze::SIZE; ++mazeColumn) {
        MazePosition currentPosition{mazeRow, mazeColumn};
        MazeCard card = game_->getMaze().getCardAt(currentPosition);
        if (game_->isAPlayerAt(currentPosition)) {
            vector<Player> players = game_->getPlayersAt(currentPosition);
            printMazeCardPart(card, part, getPlayersIcons(players));
        } else {
            printMazeCardPart(card, part);
        }
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
                out_  << row << " ";
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
    vector<Player> players = game_->getPlayers();
    for (unsigned player = 0; player < players.size(); ++player) {
        out_ << toString(players.at(player)) << endl;
    }
}

void Output::printMazeObjectives() const
{
    Object current = game_->getCurrentPlayer().getCurrentObjective().getObject();
    for (unsigned row = 0; row < Maze::SIZE; ++row) {
        for (unsigned column = 0; column < Maze::SIZE; ++column) {
            MazeCard card = game_->getMaze().getCardAt(MazePosition{row, column});
            if (card.isMarked()) {
                out_ << "(" + to_string(row) + "; " + to_string(column) + ")";
                out_ << ": " << toString(card.getObject());
                if (card.getObject() == current) out_ << " [TO FIND]\n";
                else out_ << "\n";
            }
        }
    }
}

void Output::printCurrentPlayerObjective() const
{
    Object o = game_->getCurrentPlayer().getCurrentObjective().getObject();
    print(toString(o) + " at " + toString(game_->getObjectivePosition(o)));
}

void Output::printCurrentMazeCard() const
{
    for (unsigned part = 0; part < 3; ++part) {
        printMazeCardPart(game_->getCurrentMazeCard(), part);
        out_ << "\n";
    }
}

void Output::printWinner() const
{
    Player winner = game_->getWinner();
    out_ << "Well done " << toString(winner.getColor()) << " player, ";
    out_ << "YOU WIN!" << endl;
}

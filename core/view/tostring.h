#ifndef TOSTRING_H
#define TOSTRING_H

#include <string>
#include <sstream>
#include <array>
#include "Player.h"
#include "Object.h"

using namespace std;
using namespace labyrinth;

namespace labyrinth { namespace view {

#include <iostream>

inline string toString(const Object &object) {
    array<string, 25> objectNames{
        "ghost", "gnome", "dragon", "fairy", "bat", "genie", "owl", "scarab",
        "rat", "spider", "butterfly", "lizard", "grimoire", "purse of gold",
        "map", "crown", "keys", "bones", "ring", "treasure chest", "emerald",
        "sword", "chandelier", "helmet", "none"
    };
    return objectNames[static_cast<unsigned>(object)];
}

inline string toString(const Player::Color &color) {
    switch (color)
    {
    case Player::Color::BLUE:
        return "Blue";
    case Player::Color::YELLOW:
        return "Yellow";
    case Player::Color::GREEN:
        return "Green";
    case Player::Color::RED:
        return "Red";
    }
}

inline string toString(const Player::State &State) {
    switch (State)
    {
    case Player::State::WAITING:
        return "waiting";
    case Player::State::MOVED_PATHWAYS:
        return "moving pathways";
    case Player::State::MOVED_PIECE:
        return "moving piece";
    }
}

inline string toString(const MazePosition &position) {
    stringstream ss;
    ss << "(" << position.getRow() << "; " << position.getColumn() << ")";
    return ss.str();
}

inline string toString(const Player &player)
{
    stringstream ss;
    ss << toString(player.getColor()) << " Player [state: ";
    ss << toString(player.getState()) << " | position: ";
    ss << toString(player.getPosition());
    ss << " | objective: ";
    ss << toString(player.getCurrentObjective()->getObject()) << "]";
    return ss.str();
}

}}

#endif // TOSTRING_H

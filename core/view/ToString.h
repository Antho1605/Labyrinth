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
    string str;
    switch (color)
    {
    case Player::Color::BLUE:
        str = "Blue";
        break;
    case Player::Color::YELLOW:
        str = "Yellow";
        break;
    case Player::Color::GREEN:
        str = "Green";
        break;
    case Player::Color::RED:
        str = "Red";
        break;
    }
    return str;
}

inline string toIcon(const Player::Color &color) {
    string icon;
    switch (color)
    {
    case Player::Color::BLUE:
        icon = " b ";
        break;
    case Player::Color::YELLOW:
        icon = " y ";
        break;
    case Player::Color::GREEN:
        icon = " g ";
        break;
    case Player::Color::RED:
        icon = " r ";
    }
    return icon;
}

inline string toString(const Player::State &State) {
    string str;
    switch (State)
    {
    case Player::State::WAITING:
        str = "waiting";
        break;
    case Player::State::READY_TO_MOVE:
        str = "moving pathways";
        break;
    case Player::State::DONE:
        str = "moving piece";
    }
    return str;
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
    ss << toString(player.getCurrentObjective().getObject()) << "]";
    return ss.str();
}

}}

#endif // TOSTRING_H

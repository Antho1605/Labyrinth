#include "Keyboard.h"
#include "View.h"

#include <string>
#include <array>
#include <algorithm>

using namespace nvs;

namespace labyrinth { namespace view {

static std::array<std::string, 4> COMMANDS {
    "help", "exit", "show", "pass"
};

static bool isValidCommand(std::string command)
{
    return std::find(COMMANDS.begin(), COMMANDS.end(), command) != COMMANDS.end();
}

unsigned View::readCoordinate(std::string msg) const
{
    unsigned coordinate{0};
    do {
        try {
            std::cout << msg;
            coordinate = lineFromKbd<unsigned>();
        } catch (const std::exception & e) {
            std::cout << "The coordinate should be a number between 1 and 7! ";
            std::cout << "(" << e.what() << ")" << std::endl;
        }
    }
    while (coordinate < 1 || 7 < coordinate);
    return coordinate;
}

unsigned View::readAge(std::string msg) const
{
    unsigned age{0};
    do {
        try {
            std::cout << msg;
            age = lineFromKbd<unsigned>();
        } catch (const std::exception & e) {
            std::cout << "The age should be a number between 1 and 200! ";
            std::cout << "(" << e.what() << ")" << std::endl;
        }
    }
    while (age < 1 || 200 < age);
    return age;
}

std::string View::readCommand(std::string msg) const
{
    std::string command;
    do {
        try {
            std::cout << msg;
            command = lineFromKbd<std::string>();
        } catch (const std::exception & e) {
            std::cout << "Invalid command entered! ";
            std::cout << "(" << e.what() << ")" << std::endl;
        }
    }
    while (!isValidCommand(command));
    return command;
}

}}

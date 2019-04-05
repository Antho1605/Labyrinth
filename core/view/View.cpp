#include "Keyboard.h"
#include "View.h"

#include <string>
#include <array>
#include <algorithm>

using namespace nvs;
using namespace std;

namespace labyrinth { namespace view {

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

static vector<string> tokenize(string &str)
{
    stringstream ss(str);
    vector<string> tokens;
    string token;
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> View::readCommand() const
{
    string command;
    printPrompt();
    getline(std::cin, command);
    return tokenize(command);
}

}}

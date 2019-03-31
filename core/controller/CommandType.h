#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H

#include <map>
#include <string>

namespace labyrinth { namespace controller {

enum CommandType {
    HELP,
    MOVE,
    SHOW,
    INSERT,
    EXIT
};


inline CommandType &operator++(CommandType &type) {
    type = static_cast<CommandType>(type + 1);
    return type;
}

inline std::string toString(const CommandType &type) {
    std::string commands[5] = {"help", "move", "show", "insert", "exit"};
    return commands[static_cast<int>(type)];
}

inline CommandType fromString(const std::string &str) {
    std::map<std::string, CommandType> commands;
    for (CommandType c = HELP; c <= EXIT; ++c) commands[toString(c)] = c;
    if (commands.find(str) != commands.end()) {
        return commands[str];
    } else {
        throw std::invalid_argument(str + " is not a command!");
    }
}

}}

#endif

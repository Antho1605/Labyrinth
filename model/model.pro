include(../defaults.pri)

TEMPLATE = lib
TARGET = model
DESTDIR = ../lib

SOURCES += \
    MazeCardShape.cpp \
    Objectivesdeck.cpp \
    MazePosition.cpp \
    maze.cpp \
    game.cpp

HEADERS += \
    MarkedMazeCard.h \
    Maze.h \
    MazeCard.h \
    MazePosition.h \
    Game.h \
    Object.h \
    ObjectCard.h \
    Player.h \
    MazeCardShape.h \
    Objectivesdeck.h

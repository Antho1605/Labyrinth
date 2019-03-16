include(../defaults.pri)

TEMPLATE = lib
TARGET = model
DESTDIR = ../lib

SOURCES += \
    MazeCard.cpp \
    MazeCardShape.cpp \
    Objectivesdeck.cpp \
    MazePosition.cpp

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

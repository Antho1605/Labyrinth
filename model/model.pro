include(../defaults.pri)

TEMPLATE = lib
TARGET = model
DESTDIR = ../lib

SOURCES += \
    MazeCardShape.cpp \
    ObjectivesDeck.cpp \
    MazePosition.cpp \
    maze.cpp \
    game.cpp \
    MazeCardsBuilder.cpp \
    mazecard.cpp

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
    Objectivesdeck.h \
    mazedirection.h \
    MazeCardsBuilder.h

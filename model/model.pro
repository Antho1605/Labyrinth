include(../defaults.pri)

TEMPLATE = lib
TARGET = model
DESTDIR = ../lib

SOURCES += \
    MazeCardShape.cpp \
    ObjectivesDeck.cpp \
    MazePosition.cpp \
    Game.cpp \
    MazeCardsBuilder.cpp \
    Mazecard.cpp \
    Maze.cpp
    Maze.cpp

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
    ObjectivesDeck.h \
    MazeDirection.h \
    MazeCardsBuilder.h

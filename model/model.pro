include(../defaults.pri)

TEMPLATE = lib
TARGET = model
DESTDIR = ../lib

SOURCES += \
    player.cpp \
    MazeCardShape.cpp \
    Objectivesdeck.cpp \
    main.cpp

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

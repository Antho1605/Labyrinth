TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Main.cpp \
    MazeCard.cpp \
    tests/MazeCardTest.cpp \
    tests/playertests.cpp \
    player.cpp \
    MazeCardShape.cpp \
    tests/MazeCardShapeTest.cpp

HEADERS += \
    MarkedMazeCard.h \
    Maze.h \
    MazeCard.h \
    MazePosition.h \
    Game.h \
    Object.h \
    ObjectCard.h \
    Player.h \
    tests/catch.hpp \
    MazeCardShape.h

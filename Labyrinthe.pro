TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    MazePosition.h \
    Game.h \
    Player.h \
    Object.h \
    ObjectCard.h \
    Maze.h \
    MazeCard.h \
    MarkedMazeCard.h

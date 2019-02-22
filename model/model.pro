TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    MazeCard.cpp

HEADERS += \
    MarkedMazeCard.h \
    Maze.h \
    MazeCard.h \
    MazePosition.h \
    Game.h \
    Object.h \
    ObjectCard.h \
    Player.h

include(../defaults.pri)

TEMPLATE = app
CONFIG += console

SOURCES += \
    Main.cpp \
    MazeCardShapeTest.cpp \
    MazeCardTest.cpp \
    ObjectivesDeckTest.cpp \
    PlayerTest.cpp \
    MazeAdjacencyTest.cpp \
    MazeTest.cpp \
    MazePositionTest.cpp \
    MazeCardsBuilderTest.cpp \
    InsertAtTest.cpp \
    GameInitializationTest.cpp \
    ../core/model/Game.cpp \
    ../core/model/Maze.cpp \
    ../core/model/mazecard.cpp \
    ../core/model/MazeCardsBuilder.cpp \
    ../core/model/MazeCardShape.cpp \
    ../core/model/MazePosition.cpp \
    ../core/model/ObjectivesDeck.cpp \
    GameTest.cpp \
    Shiftplayertest.cpp \
    ../core/observer/Subject.cpp

HEADERS += \
    catch.hpp \
    ../core/model/Game.h \
    ../core/model/Maze.h \
    ../core/model/MazeCard.h \
    ../core/model/MazeCardsBuilder.h \
    ../core/model/MazeCardShape.h \
    ../core/model/MazeDirection.h \
    ../core/model/MazePosition.h \
    ../core/model/Object.h \
    ../core/model/ObjectCard.h \
    ../core/model/ObjectivesDeck.h \
    ../core/model/Player.h \
    ../core/observer/Observer.h \
    ../core/observer/Subject.h

DESTDIR = $$PWD/../build

INCLUDEPATH += \
    ../core/model \
    ../core/model/model \

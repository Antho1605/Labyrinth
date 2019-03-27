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
    ../core/Game.cpp \
    ../core/Maze.cpp \
    ../core/mazecard.cpp \
    ../core/MazeCardsBuilder.cpp \
    ../core/MazeCardShape.cpp \
    ../core/MazePosition.cpp \
    ../core/ObjectivesDeck.cpp

HEADERS += \
    catch.hpp \
    ../core/Game.h \
    ../core/Maze.h \
    ../core/MazeCard.h \
    ../core/MazeCardsBuilder.h \
    ../core/MazeCardShape.h \
    ../core/MazeDirection.h \
    ../core/MazePosition.h \
    ../core/Object.h \
    ../core/ObjectCard.h \
    ../core/ObjectivesDeck.h \
    ../core/Player.h

INCLUDEPATH += \
    ../core \

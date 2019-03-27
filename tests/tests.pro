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
    ../model/Game.cpp \
    ../model/Maze.cpp \
    ../model/mazecard.cpp \
    ../model/MazeCardsBuilder.cpp \
    ../model/MazeCardShape.cpp \
    ../model/MazePosition.cpp \
    ../model/ObjectivesDeck.cpp

HEADERS += \
    catch.hpp \
    ../model/Game.h \
    ../model/Maze.h \
    ../model/MazeCard.h \
    ../model/MazeCardsBuilder.h \
    ../model/MazeCardShape.h \
    ../model/MazeDirection.h \
    ../model/MazePosition.h \
    ../model/Object.h \
    ../model/ObjectCard.h \
    ../model/ObjectivesDeck.h \
    ../model/Player.h

INCLUDEPATH += \
    ../model \

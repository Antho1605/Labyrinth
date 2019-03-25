include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -lmodel

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
    insertattest.cpp

HEADERS += \
    catch.hpp

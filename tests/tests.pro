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
    mazeadjacencytest.cpp \
    mazetest.cpp \
    mazepositiontest.cpp \
    mazecardsbuildertest.cpp

HEADERS += \
    catch.hpp

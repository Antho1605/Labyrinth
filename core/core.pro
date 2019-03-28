include(../defaults.pri)

TEMPLATE = app
TARGET = core

SOURCES += \
    Main.cpp \
    model/Game.cpp \
    model/Maze.cpp \
    model/mazecard.cpp \
    model/MazeCardsBuilder.cpp \
    model/MazeCardShape.cpp \
    model/MazePosition.cpp \
    model/ObjectivesDeck.cpp \
    view/View.cpp \
    view/Output.cpp \

HEADERS += \
    model/Game.h \
    model/MarkedMazeCard.h \
    model/Maze.h \
    model/MazeCard.h \
    model/MazeCardsBuilder.h \
    model/MazeCardShape.h \
    model/MazeDirection.h \
    model/MazePosition.h \
    model/Object.h \
    model/ObjectCard.h \
    model/ObjectivesDeck.h \
    model/Player.h \
    view/Output.h \
    view/View.h \
    view/toString.h

DESTDIR = $$PWD/../build

INCLUDEPATH += \
    $$PWD \
    model \
    view \


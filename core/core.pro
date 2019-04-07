include(../defaults.pri)

TEMPLATE = app
TARGET = core
CONFIG += console

SOURCES += \
    Main.cpp \
    model/Game.cpp \
    model/Maze.cpp \
    model/MazeCard.cpp \
    model/MazeCardsBuilder.cpp \
    model/MazeCardShape.cpp \
    model/MazePosition.cpp \
    model/ObjectivesDeck.cpp \
    view/Output.cpp \
    view/View.cpp

HEADERS += \
    model/Game.h \
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
    view/ToString.h \
    view/Keyboard.h \
    view/StringConvert.h \
    controller/Command.h \
    controller/HelpCommand.h \
    controller/Controller.h \
    controller/CommandFactory.h \
    controller/ExitCommand.h \
    controller/CommandType.h \
    controller/MovePlayerCommand.h \
    controller/ShowCommand.h \
    controller/InsertCommand.h \
    controller/RotateCommand.h \
    controller/PassMoveCommand.h

DESTDIR = $$PWD/../build

INCLUDEPATH += \
    $$PWD \
    model \
    view \
    controller \


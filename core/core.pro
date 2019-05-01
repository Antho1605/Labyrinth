include(../defaults.pri)

QT += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = labyrinth

SOURCES += \
    Main.cpp \
    model/Game.cpp \
    model/Maze.cpp \
    model/MazeCard.cpp \
    model/MazeCardsBuilder.cpp \
    model/MazeCardShape.cpp \
    model/MazePosition.cpp \
    model/ObjectivesDeck.cpp \
    view/console/Output.cpp \
    view/console/View.cpp \
    view/gui/GameWindow.cpp \
    observer/Subject.cpp \
    view/gui/PlayerDataWidget.cpp

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
    view/console/Output.h \
    view/console/View.h \
    view/console/ToString.h \
    view/console/Keyboard.h \
    view/console/StringConvert.h \
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
    controller/PassMoveCommand.h \
    view/gui/GameWindow.h \
    observer/Observer.h \
    observer/Subject.h \
    view/gui/PlayerDataWidget.h

DESTDIR = $$PWD/../build

INCLUDEPATH += \
    $$PWD \
    model \
    controller \
    view/gui \
    view/console \
    observer

FORMS += \
    view/gui/GameWindow.ui \
    view/gui/PlayerDataWidget.ui

RESOURCES += \
    resources.qrc


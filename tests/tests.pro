include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -lmodel

SOURCES += \
    main.cpp \
    MazeCardShapeTest.cpp \
    MazeCardTest.cpp \
    objectivesdecktest.cpp \
    playertests.cpp

HEADERS += \
    catch.hpp

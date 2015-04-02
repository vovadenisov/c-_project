TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -lSDL

SOURCES += main.cpp

LIBS += -lSDL

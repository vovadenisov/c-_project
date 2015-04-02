TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ourproject.cpp

HEADERS += \
    ourproject.h

LIBS += -lSDL

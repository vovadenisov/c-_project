TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ourproject.cpp \
    container.cpp \
    allclass.cpp

HEADERS += \
    ourproject.h \
    form.h \
    container.h \
    allclass.h

LIBS += -lSDL -lSDL_image

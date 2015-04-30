TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ourproject.cpp \
    ReadFile.cpp \
    elemcont.cpp \
    container.cpp \
    allclass.cpp

HEADERS += \
    ourproject.h \
    ReadFile.h \
    form.h \
    elemcont.h \
    container.h \
    allclass.h

LIBS += -lSDL -lSDL_image

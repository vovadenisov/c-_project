TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ourproject.cpp \
    container.cpp \
    allclass.cpp \
    Server.cpp \
    wrapper.cpp \
    textcontainer.cpp\
    Client.cpp \
    factory.cpp

HEADERS += \
    ourproject.h \
    form.h \
    container.h \
    allclass.h \
    Server.h \
    wrapper.h \
    textcontainer.h\
    Client.h \
    factory.h


LIBS += -lSDL -lSDL_image -lSDL_ttf

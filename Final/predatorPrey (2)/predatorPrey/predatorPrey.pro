TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    grid.cpp \
    creature.cpp \
    predator.cpp \
    prey.cpp \
    coords.cpp \
    walls.cpp \
    random.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    grid.h \
    creature.h \
    predator.h \
    prey.h \
    coords.h \
    constants.h \
    walls.h \
    random.h


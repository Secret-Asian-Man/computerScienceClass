TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    grid.cpp \
    object.cpp \
    coords.cpp \
    random.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    grid.h \
    object.h \
    constants.h \
    coords.h \
    random.h


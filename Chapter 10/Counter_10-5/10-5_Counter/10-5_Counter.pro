TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    counter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    counter.h


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    month.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    month.h


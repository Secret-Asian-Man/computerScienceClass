TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bigint.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    bigint.h


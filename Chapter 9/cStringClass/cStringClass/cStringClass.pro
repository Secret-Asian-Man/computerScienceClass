TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stringclass.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    mycstrings.h \
    stringclass.h


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    rationalnumbers.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    rationalnumbers.h \
    Tools.h \
    MyCStrings.h


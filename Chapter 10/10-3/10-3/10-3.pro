TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cdaccount.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    cdaccount.h


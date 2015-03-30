TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    iterator.cpp \
    node.cpp \
    list.cpp \
    linkedlistfunctions.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    iterator.h \
    node.h \
    list.h \
    linkedlistfunctions.h


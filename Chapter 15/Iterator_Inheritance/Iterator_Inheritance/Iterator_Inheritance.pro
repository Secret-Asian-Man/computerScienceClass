TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cursoredlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    iterator.h \
    linkedlistfunctions.h \
    list.h \
    node.h \
    stack.h \
    cursoredlist.h

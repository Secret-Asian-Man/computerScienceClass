TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    stack.cpp \
    linkedlistfunctions.cpp \
    node.cpp \
    Iterator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    stack.h \
    linkedlistfunctions.h \
    node.h \
    Iterator.h


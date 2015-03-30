TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

INCLUDEPATH += ..\..\..\includes

SOURCES += main.cpp \
    list.cpp \
    ../../../includes/LinkedListFuncs/linkedlistfunctions.cpp \
    ../../../includes/nodes/node.cpp \
    random.cpp \
    queue.cpp \
    stack.cpp \
    sortedunique.cpp


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    ../../../includes/LinkedListFuncs/linkedlistfunctions.h \
    ../../../includes/nodes/node.h \
    random.h \
    queue.h \
    stack.h \
    sortedunique.h


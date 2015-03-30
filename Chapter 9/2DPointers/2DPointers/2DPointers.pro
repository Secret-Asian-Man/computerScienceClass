TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lowlevelfunctions_2dpointers.cpp \
    twodpointerclass.cpp \
    lab.cpp \
    plane.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    lowlevelfunctions_2dpointers.h \
    twodpointerclass.h \
    lab.h \
    plane.h


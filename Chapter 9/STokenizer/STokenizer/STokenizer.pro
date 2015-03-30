TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stringclass.cpp \
    stokenize.cpp \
    token.cpp \
    mycstrings.cpp \
    ftokenize.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stringclass.h \
    mycstrings.h \
    stokenize.h \
    token.h \
    ftokenize.h


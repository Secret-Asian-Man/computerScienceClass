TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


SOURCES += main.cpp \
    numbertoken.cpp \
    operatortoken.cpp \
    openparenthesistoken.cpp \
    closedparenthesistoken.cpp \
    tokencontainer.cpp \
    token.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    numbertoken.h \
    operatortoken.h \
    openparenthesistoken.h \
    closedparenthesistoken.h \
    constants.h \
    tokencontainer.h \
    token.h \
    MyCStrings.h


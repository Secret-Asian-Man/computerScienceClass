TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    point.cpp \
    game.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    point.h \
    game.h


INCLUDEPATH += "C:/sfml-2.2/include/"

LIBS += -L"C:/sfml-2.2/lib/"

CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-network-d -lsfml-system-d
CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

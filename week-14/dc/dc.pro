QT = core
QT -= gui

CONFIG += c++11

TARGET = dc
CONFIG += console

TEMPLATE = app

SOURCES += \
    main.cpp \
    console.cpp

HEADERS += \
    console.h

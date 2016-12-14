QT += core
QT -= gui

CONFIG += c++11

TARGET = BrassPlusPlus-ABC
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    brassabc.cpp

HEADERS += \
    brassabc.h

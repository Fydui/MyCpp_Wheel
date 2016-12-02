QT += core
QT -= gui

CONFIG += c++11

TARGET = tabtenn
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    TableTennisPlayer.cpp

HEADERS += \
    TableTennisPlayer.h

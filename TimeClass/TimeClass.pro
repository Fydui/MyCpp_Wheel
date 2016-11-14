QT += core
QT -= gui

CONFIG += c++11

TARGET = TimeClass
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tmime.cpp

HEADERS += \
    tmime.h

QT += core
QT -= gui

CONFIG += c++11

TARGET = StringBad
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    StringBad.cpp \
    stringptr.cpp

HEADERS += \
    StringBad.h \
    stringptr.h

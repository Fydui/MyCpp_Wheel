QT += core
QT -= gui

CONFIG += c++11

TARGET = String-shared_ptr
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    stringptr.cpp

HEADERS += \
    stringptr.h

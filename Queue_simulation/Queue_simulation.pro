QT += core
QT -= gui

CONFIG += c++11

TARGET = Queue_simulation
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    queue.cpp

HEADERS += \
    queue.h

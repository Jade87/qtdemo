QT       -= gui

TARGET = getprocesslist
CONFIG   += console
CONFIG   -= app_bundleT

TEMPLATE = app
SOURCES += main.cpp \
    systemwin32.cpp
HEADERS += systemwin32.h

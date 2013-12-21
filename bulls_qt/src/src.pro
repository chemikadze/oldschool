SOURCES += main.cpp \
 bullsmw.cpp \
 bulls.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = ../bin/bulls_qt

FORMS += bullsmw.ui

HEADERS += bullsmw.h \
ui_bullsmw.h \
bulls.h

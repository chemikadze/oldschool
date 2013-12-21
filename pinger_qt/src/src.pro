SOURCES += main.cpp \
 pinger_mv.cpp \
 pinger.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = pinger_qt
DESTDIR = ../bin
RESOURCES -= application.qrc

FORMS += pinger_mv.ui

HEADERS += ui_pinger_mv.h \
pinger_mv.h \
pinger.h \
main.h

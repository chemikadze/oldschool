# Makefile

CPPFLAGS = -O2

SRC = bulls.h bulls.cpp
MAINBULLS = main.cpp
MAINTEST = test.cpp

SRCOBJS = bulls.o
MAINBULLSOBJS = main.o
MAINTESTOBJS = test.o

TESTBIN = test.bin
BULLSBIN = bulls.bin
BINFILES = $(TESTBIN) $(BULLSBIN)

all: test bulls

bulls.bin: $(MAINBULLSOBJS) $(SRCOBJS) 
	g++ $(CPPFLAGS) -o $(BULLSBIN) $(MAINBULLSOBJS)  $(SRCOBJS)
test.bin:  $(MAINTESTOBJS)  $(SRCOBJS)
	g++ $(CPPFLAGS) -o $(TESTBIN) $(MAINTESTOBJS) $(SRCOBJS)

test: $(TESTBIN)
.PHONY: test

bulls: $(BULLSBIN)
.PHONY: bulls

clear:
	rm -vf *.o *.gch *.bin
.PHONY: clear

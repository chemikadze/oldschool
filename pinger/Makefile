CXXFLAGS = "-ggdb"

SIMPLESRC = pinger.cpp
SIMPLEBIN = pinger.bin
SIMPLEOBJ = pinger.o

SOURCES = $(SIMPLESRC)
OBJECTS =

default: pinger.bin
.PHONY: default

pinger.bin: $(SIMPLEOBJ)
	g++ $(CXXFLAGS) -o $(SIMPLEBIN) $(SIMPLEOBJ)

clear:
	rm -rf *.o *.bin
.PHONY: clear

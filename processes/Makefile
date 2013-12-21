CPPFLAGS = -ggdb

default: execv.bin fork.bin printargs.bin nasrat.bin
.PHONY: default

execv.bin: execv.o
	g++ $(CPPFLAGS) -o execv.bin execv.o

fork.bin:  fork.o
	g++ $(CPPFLAGS) -o fork.bin fork.o

printargs.bin: printargs.o
	g++ $(CPPFLAGS) -o printargs.bin printargs.o

nasrat.bin: nasrat.o
	g++ $(CPPFLAGS) -o nasrat.bin nasrat.o

clear:
	rm *.bin *.o
.PHONY: clear

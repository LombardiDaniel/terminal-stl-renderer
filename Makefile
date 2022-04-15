# This makefile is made for the `mingw32-make`, NOT for gnu-make

GCCFLAGS=-std=c++17
INCLUDEDLLFLAGS=-static-libstdc++ -static-libgcc
DISABLEWARN=--disable-stdcall-fixup -Wwrite-strings

TermRendererSTL.exe: main.o engine.o utils.o
	g++ $(GCCFLAGS) main.o engine.o utils.o -o TermRendererSTL.exe C:\Windows\System32\winmm.dll $(INCLUDEDLLFLAGS) $(DISABLEWARN)

main.o: src/main.cpp
	g++ $(GCCFLAGS) -c src/main.cpp

engine.o: src/engine.cpp src/headers/engine.h
	g++ $(GCCFLAGS) -c src/engine.cpp

utils.o: src/utils.cpp
	g++ $(GCCFLAGS) -c src/utils.cpp

clean:
	del *.o
	del *.exe

cleanAll:
	del *.o src\headers\*.h.gch *.log

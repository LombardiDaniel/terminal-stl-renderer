# This makefile is made for the `mingw32-make`, NOT for gnu-make

GCCFLAGS=-std=c++17
INCLUDEDLLFLAGS=-static-libstdc++ -static-libgcc
DISABLEWARN=-Wwrite-strings
LINKERDISABLEWARN=--disable-stdcall-fixup

TermRendererSTL.exe: main.o engine.o utils.o
	g++ $(GCCFLAGS) main.o engine.o utils.o -o TermRendererSTL.exe C:\Windows\System32\winmm.dll $(INCLUDEDLLFLAGS) $(LINKERDISABLEWARN) $(DISABLEWARN)

main.o: src/main.cpp
	g++ $(GCCFLAGS) -c src/main.cpp $(DISABLEWARN)

engine.o: src/engine.cpp src/headers/engine.h
	g++ $(GCCFLAGS) -c src/engine.cpp $(DISABLEWARN)

utils.o: src/utils.cpp src/headers/utils.h
	g++ $(GCCFLAGS) -c src/utils.cpp $(DISABLEWARN)

clean:
	del *.o
	del *.exe

cleanAll:
	del *.o src\headers\*.h.gch *.log

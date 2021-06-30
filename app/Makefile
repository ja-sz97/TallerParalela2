CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm
DEL=rm -fr

carpetas:
	mkdir -p bin
#	mv datos.csv /al

main: carpetas main.cpp funciones.o
	$(CXX) $(CXXFLAGS) -o bin/programa main.cpp funciones.o $(LDFLAGS)

funciones.o: funciones.h funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp

clean:
	$(DEL) *.o app bin al


.PHONY: dist
dist: main

	$(DEL) *.o
.PHONY: limpiar
limpiar: clean
#
# makefile for Framework supporting the DOT FastLane project
# COP3330 Proj4
# Ruben Navarro
#

all: stester.x vtester.x

stester.o: shapes.h shapes.cpp stester.cpp
	g++ -std=c++11 -I. -Wall -Wextra -c shapes.cpp stester.cpp

shapes.o: shapes.h shapes.cpp stester.cpp
	g++ -std=c++11 -I. -Wall -Wextra -c shapes.cpp stester.cpp

stester.x: shapes.o stester.o
	g++ -std=c++11 -I. -Wall -Wextra -o stester.x shapes.o stester.o

vtester.o: vehicles.h vtester.cpp vehicles.cpp shapes.h
	g++ -std=c++11 -I. -Wall -Wextra -c vehicles.cpp vtester.cpp

vehicles.o: vehicles.h vtester.cpp vehicles.cpp shapes.h
	g++ -std=c++11 -I. -Wall -Wextra -c vehicles.cpp vtester.cpp

vtester.x: vtester.o vehicles.o
	g++ -std=c++11 -I. -Wall -Wextra -o vtester.x vehicles.o vtester.o

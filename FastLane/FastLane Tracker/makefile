#
# makefile for DOT Fastlane project
# Ruben Navarro
# RN16G
# 10/27/2017
#

cflags = -I. -Wall -Wextra
#CC     = clang++ -std=c++11
CC     = g++ -std=c++11

AREA51  = /home/courses/cop3330p/LIB/area51

all:         clients benchmarks
clients:     stester.x vtester.x tracker.x
benchmarks:  stester_i.x vtester_i.x tracker_i.x 

# build executables

tracker.x: tracker.o vehicles.o
	$(CC) -otracker.x tracker.o vehicles.o

stester.x: shapes.o stester.o
	$(CC) -ostester.x shapes.o stester.o 


vtester.x: vtester.o vehicles.o
	$(CC) -ovtester.x vehicles.o vtester.o


# build object code files

tracker.o: vehicles.h tracker.cpp
	$(CC) $(cflags) -c tracker.cpp

stester.o: shapes.h shapes.cpp stester.cpp
	$(CC) $(cflags) -c shapes.cpp stester.cpp   

vtester.o: vehicles.h vtester.cpp vehicles.cpp shapes.h
	$(CC) $(cflags) -c vehicles.cpp vtester.cpp   

shapes.o: shapes.h shapes.cpp stester.cpp
	$(CC) $(cflags) -c shapes.cpp stester.cpp

vehicles.o: vehicles.h shapes.h vehicles.cpp vtester.cpp
	$(CC) $(cflags) -c vehicles.cpp vtester.cpp


# build benchmarks

tracker_i.x: $(AREA51)/tracker_i.x
	cp   $(AREA51)/tracker_i.x .
	chmod 700 tracker_i.x

stester_i.x: $(AREA51)/stester_i.x
	cp   $(AREA51)/stester_i.x .
	chmod 700 stester_i.x     

vtester_i.x: $(AREA51)/vtester_i.x
	cp   $(AREA51)/vtester_i.x .
	chmod 700 vtester_i.x     



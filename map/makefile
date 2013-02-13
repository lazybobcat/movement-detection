CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic

all: map

map: main.o map.o
	$(CXX) -o $@ $^ file.o image.o conversions_pgm.o vector.o

main.o: main.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf main.o map.o map

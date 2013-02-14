CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-L . -lmaths -limage_pgm

all: map

map: main.o map.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o: main.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf main.o map.o map

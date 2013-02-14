CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic

all: libimage_pgm.a

libimage_pgm.a: image.o file.o
	ar cr $@ $^

image.o: image.cpp image.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
file.o: file.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf *.o

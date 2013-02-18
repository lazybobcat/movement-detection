CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic
OUTPUT=libimage_pgm.a

all: $(OUTPUT)

$(OUTPUT): image.o file.o
	ar cr $@ $^

image.o: image.cpp image.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
file.o: file.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf *.o $(OUTPUT)

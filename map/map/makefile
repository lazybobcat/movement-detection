CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic
OUTPUT=libmap.a

all: $(OUTPUT)

$(OUTPUT): map.o
	ar cr $@ $^

map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf *.o $(OUTPUT)

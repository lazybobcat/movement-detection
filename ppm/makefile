CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-L . -lmaths
OUTPUT=ppm

all: $(OUTPUT)

$(OUTPUT): main.cpp filters.o image.o shapedetection.o pixel.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf *.o $(OUTPUT)


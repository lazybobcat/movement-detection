CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic
OUTPUT=libmaths.a

all: $(OUTPUT)

$(OUTPUT): conversions_ppm.o conversions_pgm.o matrix.o vector.o rectangle.o
	ar cr $@ $^

conversions_ppm.o: conversions_ppm.cpp conversions.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
conversions_pgm.o: conversions_pgm.cpp conversions.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
vector.o: vector.cpp vector.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
rectangle.o: rectangle.cpp rectangle.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf *.o $(OUTPUT)

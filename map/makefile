CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-L . -lmaths -limage_pgm
LIBS=libmaths.a libimage_pgm.a
OUTPUT=libmap.a

all: $(OUTPUT)

$(OUTPUT): map.o
	ar cr $@ $^

map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

libmaths.a: ../maths/libmaths.a
	cp ../maths/libmaths.a .
libimage_pgm.a: ../pgm/libimage_pgm.a
	cp ../pgm/libimage_pgm.a .

../maths/libmaths.a:
	make -C ../maths
../pgm/libimage_pgm.a:
	make -C ../pgm

clean:
	rm -rf *.o $(LIBS) $(OUTPUT)

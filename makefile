CXX=g++
CXXFLAGS=
LDFLAGS=-L . -lmaths -limage_pgm -lmap
OUTPUT=bin

all: $(OUTPUT)

$(OUTPUT): main.cpp libmaths.a libimage_pgm.a libmap.a
	$(CXX) -o $@ $^ $(LDFLAGS)

libmaths.a: maths/libmaths.a
	cp maths/libmaths.a .
libimage_pgm.a: pgm/libimage_pgm.a
	cp pgm/libimage_pgm.a .
libmap.a: map/libmap.a
	cp map/libmap.a .

maths/libmaths.a:
	make -C maths
pgm/libimage_pgm.a:
	make -C pgm
map/libmap.a:
	make -C map

clean:
	make -C maths clean
	make -C pgm clean
	make -C map clean
	rm -rf *.a $(OUTPUT)

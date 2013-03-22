CXX=g++
CXXFLAGS=
LDFLAGS=-L maths -lmaths -L pgm -limage_pgm -L map -lmap
LIBS=maths/libmaths.a pgm/libimage_pgm.a map/libmap.a
OUTPUT=tokmap addkmap tkmap rkmap

all: $(OUTPUT)

tokmap: tools/tokmap.cpp $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)

addkmap: tools/addkmap.cpp $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)

tkmap: tools/tkmap.cpp $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)

rkmap: tools/rkmap.cpp $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)

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

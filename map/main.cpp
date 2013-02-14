#include <iostream>

#include "map.h"

using namespace carto;
using namespace pgm;

int main()
{
	maths::Vector2d T = maths::Vector2d(0, 50);
	float R[4] = {0, -1, 1, 0}; 					// 90°

    try
    {
		Map m1(Image("../images/valide.pgm"));
		Map m2(Image("../images/valide.pgm"));
		
		m1.saveMap("map1");
		m2.saveMap("map2");
		
		m2.translated(T).saveMap("translated");
		m2.rotated(R).saveMap("rotated");
		m2.rt_map(R, T).saveMap("rt_map");
		m2.tr_map(T, R).saveMap("tr_map");
    }
    catch(std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "done" << std::endl;

    return 0;
}

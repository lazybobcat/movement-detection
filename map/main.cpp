#include <iostream>

#include "map.h"
#include "../maths/matrix.h"

using namespace carto;
using namespace pgm;

int main()
{
	maths::Vector2d T = maths::Vector2d(0, 50);
	float R[4];
	
	maths::matrix::rotationMatrix2d(R, 3.141592/2);

    try
    {
		Map m1(Image("../images/valide.pgm"));
		Map m2(Image("../images/valide.pgm"));
		
		m1.saveMap("map");
		m2.rotated(R).saveMap("rotated");
    }
    catch(std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "done" << std::endl;

    return 0;
}

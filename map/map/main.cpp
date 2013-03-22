#include <iostream>

#include "map.h"
#include "../maths/matrix.h"

using namespace carto;
using namespace pgm;

int main()
{
	maths::Vector2d T = maths::Vector2d(-50, -50);
	float R90[4], R135[4];
	
	maths::matrix::rotationMatrix2d(R90, CONVERT_DTOR(90));
	maths::matrix::rotationMatrix2d(R135, CONVERT_DTOR(135));

    try
    {
    /* Quelques exemples
    	Deux images chargées, sauvées, translatées, rotatées (...), bref... Si vous voulez regarder.
    	Tout s'ouvre via leur IHM.
    */
		Map m1("map");
		Map m2(Image("../images/valide.pgm"));
		
		m1.saveMap("map.cp");
		m2.rotated(R90).saveMap("rotated90");
		m2.translated(T).saveMap("translated");
		m2.rotated(R135).saveMap("rotated135");
		m2.rotated(R90).translated(T).saveMap("randtmap");
		
		(m2.rotated(R90) + m2.translated(T) + m2.rotated(R135) + m2).saveMap("allmaps");
    }
    catch(std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "done" << std::endl;

    return 0;
}

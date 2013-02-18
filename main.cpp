#include <iostream>
#include <string>
#include <assert.h>

#include "map/map.h"

using namespace carto;
using namespace carto::pgm;

int main(int argc, char **argv)
{
	assert(argc == 3);

	Image img(argv[1]);

	try
	{
		Map kmap(img);
		kmap.saveMap(argv[2]);
	}
	catch(std::exception e)
	{
   		std::cerr << e.what() << std::endl;
	}

	std::cout << "done" << std::endl;

	return 0;
}

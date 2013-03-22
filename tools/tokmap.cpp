#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

#include "../map/map.h"

using namespace carto;
using namespace carto::pgm;

int main(int argc, char **argv)
{
	char opt;
	char in[128] = "", out[128] = "";

	std::cout << "To KMAP : Get a KMAP file from a PGM file" << std::endl;

	while((opt = getopt(argc, argv, "i:o:")) != -1)
	{
		switch(opt)
		{
		case 'i':
			strcpy(in, optarg);
			break;
		case 'o':
			strcpy(out, optarg);
			break;
		default:
			std::cerr << "Usage: " << argv[0] << " -i in -o out\n";
			exit(EXIT_FAILURE);
		}
	}

	// Check
	if(!strlen(in) || !strlen(out))
	{
		std::cerr << "in and out are required (-i, -o)\n";
		exit(EXIT_FAILURE);
	}

	Image img(in);

	try
	{
		Map kmap(img);
		kmap.saveMap(out);
	}
	catch(std::exception e)
	{
   		std::cerr << e.what() << std::endl;
	}

	std::cout << "done" << std::endl;

	return 0;
}

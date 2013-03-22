#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include "../maths/matrix.h"
#include "../map/map.h"

using namespace carto;
using namespace carto::pgm;

int main(int argc, char **argv)
{
	int opt;
	float x = 0, y = 0;
	char in[128] = "", out[128] = "";

        while((opt = getopt(argc, argv, "i:o:x:y:r:")) != -1)
	{
        	switch (opt) {
               	case 'i':
			strcpy(in, optarg);
                	break;
		case 'o':
			strcpy(out, optarg);
                        break;
		case 'x':
			if(sscanf(optarg, "%f", &x) != 1)
			{
				std::cerr << "-x X : float required\n";
				exit(EXIT_FAILURE);
			}

			break;
		case 'y':
			if(sscanf(optarg, "%f", &y) != 1)
			{
				std::cerr << "-y Y : float required\n";
				exit(EXIT_FAILURE);
			}

			break;
               	default:
                   std::cerr << "Usage: " << argv[0] << " -i in -o out [-x X] [-y Y]\n";
                   exit(EXIT_FAILURE);
              	}
     	}

	// Input or output required
	if(strlen(in) == 0 || strlen(out) == 0)
	{
		std::cerr << "in and out (-i, -o) are required" << std::endl;
		exit(EXIT_FAILURE);
	}

	Map kmap_in(in);

	kmap_in.translated(maths::Vector2d(x, y)).saveMap(out);

	std::cout << "done" << std::endl;
	return 0;
}

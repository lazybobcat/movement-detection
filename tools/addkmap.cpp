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
	int angle = 0;
	char inf[128] = "", ins[128] = "", out[128] = "";

        while((opt = getopt(argc, argv, "f:s:o:x:y:r:")) != -1)
	{
        	switch (opt) {
               	case 'f':
			strcpy(inf, optarg);
                	break;
		case 's':
			strcpy(ins, optarg);
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
		case 'r':
			if(sscanf(optarg, "%d", &angle) != 1)
			{
				std::cerr << "-r R : int required\n";
				exit(EXIT_FAILURE);
			}

			break;
               	default:
                   std::cerr << "Usage: " << argv[0] << " -f inF -s inS -o out [-x X] [-y Y] [-r R]\n";
                   exit(EXIT_FAILURE);
              	}
     	}

	// Input or output required
	if(strlen(inf) == 0 || strlen(ins) == 0 || strlen(out) == 0)
	{
		std::cerr << "in_first, in_second and out (-f, -s, -o) are required" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Warning : if you want to decide yourself the order of translations and rotations, use others scripts !\n";

	Map kmap_inf(inf), kmap_ins(ins);
	float R[4];

	maths::matrix::rotationMatrix2d(R, CONVERT_DTOR(angle));

	(kmap_inf + kmap_ins.translated(maths::Vector2d(x, y)).rotated(R)).saveMap(out);

	std::cout << "done" << std::endl;
	return 0;
}

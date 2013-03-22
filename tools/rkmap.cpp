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
	int angle;
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
		case 'r':
			if(sscanf(optarg, "%d", &angle) != 1)
			{
				std::cerr << "-r R : int required\n";
				exit(EXIT_FAILURE);
			}

			break;
               	default:
                   std::cerr << "Usage: " << argv[0] << " -i in -o out [-r R]\n";
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
	float R[4];

	maths::matrix::rotationMatrix2d(R, CONVERT_DTOR(angle));

	kmap_in.rotated(R).saveMap(out);

	std::cout << "done" << std::endl;
	return 0;
}

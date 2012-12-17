#include <iostream>
#include "pixel.h"
#include "image.h"

using namespace std;
using namespace carto::ppm;

int main()
{
    Image img;
    img.loadFromFile("data/image-test.ppm");

    return 0;
}


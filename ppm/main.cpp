#include <iostream>
#include "pixel.h"
#include "image.h"
#include "filters.h"

using namespace std;
using namespace carto::ppm;

int main()
{
    Image img, img2, altered, altered2, final;
    img.loadFromFile("data/image-test.ppm");
    img2.loadFromFile("data/image-test2.ppm");

    altered = filterColor(img);
    altered.saveToFile("data/image-color-saved.ppm");

    altered = filterGrey(img);
    altered.saveToFile("data/image-grey-saved.ppm");

    altered2 = filterGrey(img2);
    altered2.saveToFile("data/image-grey-saved2.ppm");

    final = filterDiff(altered, altered2, 10);
    final.saveToFile("data/image-final-threshold10.ppm");
    final = filterDiff(altered, altered2, 90);
    final.saveToFile("data/image-final-threshold90.ppm");

    return 0;
}


#include <iostream>
#include "pixel.h"
#include "image.h"
#include "filters.h"
#include "../maths/vector.h"
#include "../maths/conversions.h"

using namespace std;
using namespace carto::ppm;
using namespace carto::maths;

int main()
{
    std::cout << std::endl;

    // Filters tests
    Image img, altered;
    img.loadFromFile("data/2.ppm");
    altered = filterThresholdBinarisation(img, Pixel(230, 64, 0), Pixel(255, 192, 255));
    altered.saveToFile("data/2-binarisation.ppm");
    img.close();
    altered.close();

    img.loadFromFile("data/1.ppm");
    altered = filterThresholdBinarisation(img, Pixel(78, 156, 116), Pixel(250, 255, 255));
    altered.saveToFile("data/1-binarisation.ppm");
    img.close();
    altered.close();

    img.loadFromFile("data/3.ppm");
    altered = filterThresholdBinarisation(img, Pixel(104, 64, 61), Pixel(221, 129, 114));
    altered.saveToFile("data/3-binarisation.ppm");
    img.close();
    altered.close();

    img.loadFromFile("data/4.ppm");
    altered = filterThresholdBinarisation(img, Pixel(230, 64, 0), Pixel(255, 192, 255));
    altered.saveToFile("data/4-binarisation.ppm");
    img.close();
    altered.close();

    img.loadFromFile("data/5.ppm");
    altered = filterThresholdBinarisation(img, Pixel(230, 64, 0), Pixel(255, 192, 255));
    altered.saveToFile("data/5-binarisation.ppm");
    img.close();
    altered.close();

    img.loadFromFile("data/6.ppm");
    altered = filterThresholdBinarisation(img, Pixel(250, 0, 0), Pixel(255, 10, 10));
    altered.saveToFile("data/6-binarisation.ppm");
    img.close();
    altered.close();

    /*Image img, img2, altered, altered2, final;
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
    final.saveToFile("data/image-final-threshold90.ppm");*/


    // Test of coordinates conversion

    /*Vector3f coords = ppm::toRGBCameraCoordinates(Vector2u(369, 304), 0.939429);
    cout << "Coordinates in meters : [" << coords.x << " , " << coords.y << " , " << coords.z << "] " << endl;*/

    return 0;
}


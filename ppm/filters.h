#ifndef FILTERS_H
#define FILTERS_H


#include "image.h"

carto::ppm::Image filterColor(carto::ppm::Image& image);
carto::ppm::Image filterGrey(carto::ppm::Image& image);
carto::ppm::Image filterDiff(carto::ppm::Image& image1, carto::ppm::Image& image2, unsigned char threshold = 133);



#endif // FILTERS_H

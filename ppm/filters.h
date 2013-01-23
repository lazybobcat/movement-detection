#ifndef FILTERS_H
#define FILTERS_H


#include "image.h"

carto::ppm::Image filterColor(carto::ppm::Image& image);
carto::ppm::Image filterGrey(carto::ppm::Image& image);
carto::ppm::Image filterDiff(carto::ppm::Image& image1, carto::ppm::Image& image2, unsigned char threshold = 133);
carto::ppm::Image filterThresholdBinarisation(carto::ppm::Image& image,
                                  const carto::ppm::Pixel& thresholdMin = carto::ppm::Pixel::Black,
                                  const carto::ppm::Pixel& thresholdMax = carto::ppm::Pixel::White);



#endif // FILTERS_H

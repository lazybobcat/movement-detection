#include "filters.h"

using namespace carto::ppm;

void filterColor(carto::ppm::Image& image)
{
    for(unsigned int y = 0; y < image.height(); ++y)
    {
        for(unsigned int x = 0; x < image.width(); ++x)
        {
            Pixel p = image.at(x, y);
            if(p.r > p.g)
            {
                if(p.r > p.b)
                    image.setPixel(x, y, Pixel::Red);
                else
                    image.setPixel(x, y, Pixel::Blue);
            }
            else
            {
                if(p.g > p.b)
                    image.setPixel(x, y, Pixel::Green);
                else
                    image.setPixel(x, y, Pixel::Blue);
            }
        }
    }
}

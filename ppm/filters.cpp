#include "filters.h"

using namespace carto::ppm;


carto::ppm::Image filterThresholdBinarisation(carto::ppm::Image& image, const carto::ppm::Pixel& thresholdMin, const carto::ppm::Pixel& thresholdMax)
{
    carto::ppm::Image alteredImage = image;
    for(unsigned int y = 0; y < alteredImage.height(); ++y)
    {
        for(unsigned int x = 0; x < alteredImage.width(); ++x)
        {
            // Get the image pixel at (x,y)
            Pixel p = alteredImage.at(x, y);

            // If the pixel isn't in the threshold, we set the pixel to black
            if(p.r < thresholdMin.r || p.g < thresholdMin.g || p.b < thresholdMin.b || p.r > thresholdMax.r || p.g > thresholdMax.g || p.b > thresholdMax.b)
            {
                alteredImage.setPixel(x, y, carto::ppm::Pixel::Black);
            }
            // Else the pixel is in the threshold, we set the pixel to white
            else
            {
                alteredImage.setPixel(x, y, carto::ppm::Pixel::White);
            }
        }
    }
    return alteredImage;
}



carto::ppm::Image filterColor(carto::ppm::Image& image)
{
    carto::ppm::Image alteredImage = image;
    for(unsigned int y = 0; y < alteredImage.height(); ++y)
    {
        for(unsigned int x = 0; x < alteredImage.width(); ++x)
        {
            Pixel p = alteredImage.at(x, y);
            if(p.r > p.g)
            {
                if(p.r > p.b)
                    alteredImage.setPixel(x, y, Pixel::Red);
                else
                    alteredImage.setPixel(x, y, Pixel::Blue);
            }
            else
            {
                if(p.g > p.b)
                    alteredImage.setPixel(x, y, Pixel::Green);
                else
                    alteredImage.setPixel(x, y, Pixel::Blue);
            }
        }
    }
    return alteredImage;
}


carto::ppm::Image filterGrey(carto::ppm::Image& image)
{
    carto::ppm::Image alteredImage = image;
    for(unsigned int y = 0; y < alteredImage.height(); ++y)
    {
        for(unsigned int x = 0; x < alteredImage.width(); ++x)
        {
            Pixel p = alteredImage.at(x, y);
            unsigned char average = p.greyValue();
            alteredImage.setPixel(x, y, Pixel(average, average, average));
        }
    }
    return alteredImage;
}

carto::ppm::Image filterDiff(carto::ppm::Image& image1, carto::ppm::Image& image2, unsigned char threshold)
{
    carto::ppm::Image alteredImage = image1;
    for(unsigned int y = 0; y < alteredImage.height(); ++y)
    {
        for(unsigned int x = 0; x < alteredImage.width(); ++x)
        {
            Pixel pImg1 = image1.at(x, y);
            Pixel pImg2 = image2.at(x, y);
            Pixel value = pImg2-pImg1;
            if(value.greyValue() < threshold)
                alteredImage.setPixel(x, y, Pixel::Black);
            else
                alteredImage.setPixel(x, y, Pixel::White);
        }
    }
    return alteredImage;
}

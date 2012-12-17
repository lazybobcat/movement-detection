#include "pixel.h"
#include <iostream>

using namespace carto::ppm;

const Pixel Pixel::Back(0,0,0);
const Pixel Pixel::Red(255,0,0);
const Pixel Pixel::Green(0,255,0);
const Pixel Pixel::Blue(0,0,255);
const Pixel Pixel::White(255,255,255);


Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue)
    : r(red), g(green), b(blue)
{
    //std::cout << "Create pixel (" << (int)r << ", " << (int)g << ", " << (int)b << ")" << std::endl;
}

Pixel::Pixel(const Pixel& copy)
{
    r = copy.r;
    g = copy.g;
    b = copy.b;
}

Pixel& Pixel::operator=(const Pixel& copy)
{
    r = copy.r;
    g = copy.g;
    b = copy.b;

    return *this;
}

bool Pixel::operator==(const Pixel& other)
{
    return (r == other.r && g == other.g && b == other.b);
}

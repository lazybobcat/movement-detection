#include "pixel.h"
#include <iostream>

using namespace carto::ppm;

const Pixel Pixel::Black(0,0,0);
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

Pixel& Pixel::operator-(const Pixel& copy)
{
    if(r > copy.r)
        r -= copy.r;
    else
        r = 0;

    if(g > copy.g)
        g -= copy.g;
    else
        g = 0;

    if(b > copy.b)
        b -= copy.b;
    else
        b = 0;

    return *this;
}

Pixel& Pixel::operator+(const Pixel& copy)
{
    if(reinterpret_cast<int>(r + copy.r) > 255)
        r = 255;
    else
        r += copy.r;

    if(reinterpret_cast<int>(g + copy.g) > 255)
        g = 255;
    else
        g += copy.g;

    if(reinterpret_cast<int>(b + copy.b) > 255)
        b = 255;
    else
        b += copy.b;

    return *this;
}

bool Pixel::operator==(const Pixel& other) const
{
    return (r == other.r && g == other.g && b == other.b);
}


unsigned char Pixel::greyValue() const
{
    return (r+g+b) / 3;
}

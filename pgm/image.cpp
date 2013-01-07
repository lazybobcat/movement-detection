#include "image.h"

using namespace carto;

pgm::Image::Image()
{
}

pgm::Image::Image(const std::string &filepath)
{
    loadFromFile(filepath);
}

pgm::Image::Image(const pgm::Image &ori)
{
    m_imgType = ori.m_imgType;
    m_width = ori.m_width;
    m_height = ori.m_height;
    m_start = ori.m_start;
    m_pixels = ori.m_pixels;
}

pgm::Image::~Image()
{
}

float pgm::Image::depth(unsigned x, unsigned y) const
{
    unsigned short depth = m_pixels.at(y * m_width + x);

    if(depth < 2047.f)
       return 1.f / (depth * -0.0030711016 + 3.3309495161);

    return 0.f;
}

unsigned int pgm::Image::width() const
{
    return m_width;
}

unsigned int pgm::Image::height() const
{
    return m_height;
}

pgm::Image &pgm::Image::operator=(const pgm::Image &ori)
{
    if(&ori == this)    return *this;

    m_imgType = ori.m_imgType;
    m_width = ori.m_width;
    m_height = ori.m_height;
    m_start = ori.m_start;
    m_pixels = ori.m_pixels;

    return *this;
}

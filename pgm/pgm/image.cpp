#include "image.h"

using namespace carto;

pgm::Image::Image()
    : m_imgType(UNKNOWN), m_width(0), m_height(0), m_colorDepth(255)
{
}

pgm::Image::Image(const std::string &filepath)
    : m_imgType(UNKNOWN), m_width(0), m_height(0), m_colorDepth(255)
{
    loadFromFile(filepath);
}

pgm::Image::Image(const pgm::Image &ori)
    : m_imgType(ori.m_imgType), m_width(ori.m_width), m_height(ori.m_height),
    m_colorDepth(ori.m_colorDepth), m_pixels(ori.m_pixels)
{
}

pgm::Image::~Image()
{
}

float pgm::Image::depth(unsigned x, unsigned y) const
{
    return toMeters(m_pixels.at(y * m_width + x));
}

float pgm::Image::maxDepth() const 
{
	float max = toMeters(*m_pixels.begin());
	for(std::vector<unsigned short>::const_iterator it = m_pixels.begin(); it != m_pixels.end(); ++it)
		if(max < toMeters(*it))	max = toMeters(*it);
	return max;
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
    m_pixels = ori.m_pixels;

    return *this;
}

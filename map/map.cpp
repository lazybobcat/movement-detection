#include <iostream>
#include <fstream>
#include <stdexcept>

#include "map.h"
#include "../maths/conversions.h"

using namespace carto;

Map::Map(const pgm::Image &pgmImage, unsigned short w, unsigned short h)
	: w(w)
{
	this->h = (pgmImage.maxDepth() * 100 > h) ? pgmImage.maxDepth() * 100 : h;
	makeMap(pgmImage);
}

Map::Map(unsigned short w, unsigned short h)
	: w(w), h(h)
{
	m_binaryMap.resize(w * h, false);
}
	
Map::Map(const Map &other)
	: m_binaryMap(other.m_binaryMap), w(other.w), h(other.h)
{
}

void Map::makeMap(const pgm::Image &pgmImage)
{
/* When we multiply by 100, its to get values in centimeters */
	// fill the map with false, with the good size
    m_binaryMap.resize(w * h, false);

	/* Get a line near of the bottom for these reasons :
	 ** The robot is small : it is useless to map objets of the image's top
	 ** After some tests, when the floor is included in the scan, it makes noise
	 and makes the map incorrect
	 => the value is experimental
	 */
    for(unsigned x = 0, y = pgmImage.height()*.5; x < pgmImage.width(); ++x)
	{
		// get the map x and y position
		unsigned posx = 100 * (maths::pgm::toRealCoordinates(maths::Vector2u(x, y), pgmImage.depth(x, y)).x + 5);
		unsigned posy = 100 * pgmImage.depth(x, y);

		m_binaryMap[posy * w + posx] = true;
	}
}

void Map::saveMap(const std::string &fileName) const
{
	std::ofstream file((fileName + ".kmap").c_str());

    if(!file.is_open())
        throw std::ios_base::failure("Error opening file for saving kmap image.");

    for(int y = h - 1; y >= 0; --y)
    {
        for(unsigned int x = 0; x < w; ++x)
            file << (m_binaryMap.at(y * w + x) ? "R" : "V");

        file << "\n";
    }

    file.close();
}

/*
 * T.z is not used because this map is 2D
 */
Map Map::translated(const maths::Vector3f &T) const
{
	Map m(w, h);
	
	for(unsigned x = 0; x < w; ++x)
		for(unsigned y = 0; y < h; ++y)
		{
			int px = x + T.x, py = y + T.y;
			if(px >= 0 && px < w && py >= 0 && py < h)
				m.m_binaryMap[py * w + px] = m_binaryMap[y * w + x];
		}

	return m;
}

Map Map::rotated(const float *R) const
{
	Map m(w, h);
	
	for(unsigned x = 0; x < w; ++x)
		for(unsigned y = 0; y < h; ++y)
		{
		// Finding the position after rotation
			int px = R[0] * x + R[1] * y, py = R[2] * x + R[3] * y;
			if(px >= 0 && px < w && py >= 0 && py < h)
				m.m_binaryMap[py * w + px] = m_binaryMap[y * w + x];
		}
	
	return m;
}

Map Map::tr_map(const maths::Vector3f &T, const float *R) const
{
	Map m(w, h);
	
	for(unsigned x = 0; x < w; ++x)
		for(unsigned y = 0; y < h; ++y)
		{
		// Finding the position after translation and rotation (in this order)
			int px = R[0] * (x + T.x) + R[1] * (y + T.y);
    		int py = R[2] * (x + T.x) + R[3] * (y + T.y);
			if(px >= 0 && px < w && py >= 0 && py < h)
				m.m_binaryMap[py * w + px] = m_binaryMap[y * w + x];
		}
	
	return m;
}

Map Map::rt_map(const float *R, const maths::Vector3f &T) const
{
	Map m(w, h);
	
	for(unsigned x = 0; x < w; ++x)
		for(unsigned y = 0; y < h; ++y)
		{
		// Finding the position after rotation and translation (in this order)
			int px = R[0] * x + R[1] * y  +  T.x;
    		int py = R[2] * x + R[3] * y  +  T.y;
			if(px >= 0 && px < w && py >= 0 && py < h)
				m.m_binaryMap[py * w + px] = m_binaryMap[y * w + x];
		}
	
	return m;
}

/*
 * This method must be called on two same sized maps !
 */
Map Map::operator+(const Map &other) const
{
	// nw and nh are new w and h. We take the little one for both
	unsigned nw = (w < other.w ? w : other.w), nh = (h < other.h ? h : other.h);

	Map m(nw, nh);
	
	for(unsigned x = 0; x < nw; ++x)
		for(unsigned y = 0; y < nh; ++y)
			m.m_binaryMap[y * nw + x] = m_binaryMap[y * w + x] || other.m_binaryMap[y * other.w + x];
	
	return m;
}


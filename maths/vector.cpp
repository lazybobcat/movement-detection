#include "vector.h"

using namespace carto::maths;

Vector2u::Vector2u(unsigned int x, unsigned int y)
	: x(x), y(y)
{
}

Vector2u::Vector2u(const Vector2u &v2u)
	: x(v2u.x), y(v2u.y)
{
}

Vector2u &Vector2u::operator=(const Vector2u &ori)
{
	if(this == &ori)	return *this;
	
	x = ori.x;
	y = ori.y;

	return *this;
}

Vector3f::Vector3f(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

Vector3f::Vector3f(const Vector3f &v3f)
	: x(v3f.x), y(v3f.y), z(v3f.z)
{
}

Vector3f::Vector3f(const Vector2u &v2u)
	: x(v2u.x), y(v2u.y), z(0)
{
}

Vector3f &Vector3f::operator=(const Vector3f &ori)
{
	if(this == &ori)	return *this;
	
	x = ori.x;
	y = ori.y;
	z = ori.z;

	return *this;
}

#include "matrix.h"
#include <cmath>

using namespace carto::maths;

Vector2d matrix::translate2d(const Vector2d &obj, const Vector2d &T)
{
	return Vector2d(obj.x + T.x, obj.y + T.y);
}

Vector2d matrix::reverse_translate2d(const Vector2d &obj, const Vector2d &T)
{
	return Vector2d(obj.x - T.x, obj.y - T.y);
}

Vector3f matrix::translate3f(const Vector3f &obj, const Vector3f &T)
{
	return Vector3f(obj.x + T.x, obj.y + T.y, obj.z + T.z);
}

Vector3f matrix::reverse_translate3f(const Vector3f &obj, const Vector3f &T)
{
	return Vector3f(obj.x - T.x, obj.y - T.y, obj.z - T.z);
}

Vector2d matrix::rotate2d(const Vector2d &obj, const float *R, const Vector2d &center)
{
	return Vector2d((obj.x - center.x) * R[0] + (obj.y - center.y) * R[1] + center.x,
					(obj.x - center.x) * R[2] + (obj.y - center.y) * R[3] + center.y);
}

Vector2d matrix::reverse_rotate2d(const Vector2d &obj, const float *R, const Vector2d &center)
{
/* In our case, R^-1 can be made like this :
[ a b
  c d ]
===>
[ a c
  b d ] */
	return Vector2d((obj.x - center.x) * R[0] + (obj.y - center.y) * R[2] + center.x,
					(obj.x - center.x) * R[1] + (obj.y - center.y) * R[3] + center.y);
}

Vector3f matrix::rotate3f(const Vector3f &obj, const float *R, const Vector3f &center)
{
	return Vector3f((obj.x - center.x) * R[0] + (obj.y - center.y) * R[1] + (obj.z - center.z) * R[2] + center.x,
					(obj.x - center.x) * R[3] + (obj.y - center.y) * R[4] + (obj.z - center.z) * R[5] + center.y,
					(obj.x - center.x) * R[6] + (obj.y - center.y) * R[7] + (obj.z - center.z) * R[8] + center.z);
}

Vector3f matrix::reverse_rotate3f(const Vector3f &obj, const float *R, const Vector3f &center)
{
/* In our case, R^-1 can be made like this :
[ a b c
  d e f
  g h i ]
===>
[ a d g
  b e h
  c f i ] */
	return Vector3f((obj.x - center.x) * R[0] + (obj.y - center.y) * R[3] + (obj.z - center.z) * R[6] + center.x,
					(obj.x - center.x) * R[1] + (obj.y - center.y) * R[4] + (obj.z - center.z) * R[7] + center.y,
					(obj.x - center.x) * R[2] + (obj.y - center.y) * R[5] + (obj.z - center.z) * R[8] + center.z);
}

void matrix::rotationMatrix2d(float *R, float angle)
{
	R[0] = cos(angle);
	R[1] = -sin(angle);
	R[2] = sin(angle);
	R[3] = cos(angle);
}


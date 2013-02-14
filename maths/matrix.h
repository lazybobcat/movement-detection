#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

namespace carto
{
    namespace maths
    {
        namespace matrix
        {
        	Vector2d translate2d(const Vector2d &obj, const Vector2d &T);
        	Vector2d reverse_translate2d(const Vector2d &obj, const Vector2d &T);
        
        	Vector3f translate3f(const Vector3f &obj, const Vector3f &T);
        	Vector3f reverse_translate3f(const Vector3f &obj, const Vector3f &T);
        	
        	Vector2d rotate2d(const Vector2d &obj, const float *R, const Vector2d &center = Vector2d(0, 0));
        	Vector2d reverse_rotate2d(const Vector2d &obj, const float *R, const Vector2d &center = Vector2d(0, 0));
        	
        	Vector3f rotate3f(const Vector3f &obj, const float *R, const Vector3f &center = Vector3f(0, 0, 0));
        	Vector3f reverse_rotate3f(const Vector3f &obj, const float *R, const Vector3f &center = Vector3f(0, 0, 0));
        }
    }
}

#endif // MATRIX_H

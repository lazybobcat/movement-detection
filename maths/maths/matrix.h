#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

/* Macro to convert any degree value into radian value */
#define CONVERT_DTOR(angle)	((angle%360) * 3.141592 / 180.f)
/* Macro to convert any radian value into degree value */
#define CONVERT_RTOD(angle) ((angle * 180.f / 3.141592)

namespace carto
{
    namespace maths
    {
        namespace matrix
        {
        	/**
        	 * @brief returns a translated vector (2D)
        	 * @param obj the original vector (non modified)
        	 * @param T the translation vector
        	 * @return the translated vector
        	 */
        	Vector2d translate2d(const Vector2d &obj, const Vector2d &T);
        	
        	/**
        	 * @brief returns an untranslated vector (2D)
        	 * @param obj the original vector (non modified)
        	 * @param T the translation vector
        	 * @return the translated vector
        	 */
        	Vector2d reverse_translate2d(const Vector2d &obj, const Vector2d &T);
        
        	/**
        	 * @brief returns a translated vector (3D)
        	 * @param obj the original vector (non modified)
        	 * @param T the translation vector
        	 * @return the translated vector
        	 */
        	Vector3f translate3f(const Vector3f &obj, const Vector3f &T);
        	
        	/**
        	 * @brief returns a translated vector (3D)
        	 * @param obj the original vector (non modified)
        	 * @param T the translation vector
        	 * @return the translated vector
        	 */
        	Vector3f reverse_translate3f(const Vector3f &obj, const Vector3f &T);
        	
        	/**
        	 * @brief returns a rotated vector (2D)
        	 * @param obj the original vector (non modified)
        	 * @param R the rotation vector
        	 * @param center center of rotation
        	 * @return the rotated vector
        	 */
        	Vector2d rotate2d(const Vector2d &obj, const float *R, const Vector2d &center = Vector2d(0, 0));
        	
        	/**
        	 * @brief returns a rotated vector (2D)
        	 * @param obj the original vector (non modified)
        	 * @param R the rotation vector
        	 * @param center center of rotation
        	 * @return the rotated vector
        	 */
        	Vector2d reverse_rotate2d(const Vector2d &obj, const float *R, const Vector2d &center = Vector2d(0, 0));
        	
        	/**
        	 * @brief returns a rotated vector (3D)
        	 * @param obj the original vector (non modified)
        	 * @param R the rotation vector
        	 * @param center center of rotation
        	 * @return the rotated vector
        	 */
        	Vector3f rotate3f(const Vector3f &obj, const float *R, const Vector3f &center = Vector3f(0, 0, 0));
        	
        	/**
        	 * @brief returns a rotated vector (3D)
        	 * @param obj the original vector (non modified)
        	 * @param R the rotation vector
        	 * @param center center of rotation
        	 * @return the rotated vector
        	 */
        	Vector3f reverse_rotate3f(const Vector3f &obj, const float *R, const Vector3f &center = Vector3f(0, 0, 0));
        	
        	/**
        	 * @brief returns a rotation matrix (2D)
        	 * @param R the rotation matrix to be filled (4 float)
        	 * @param angle the angle in radians
        	 */
        	void rotationMatrix2d(float *R, float angle);
        }
    }
}

#endif // MATRIX_H

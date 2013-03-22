#include "conversions.h"
#include "matrix.h"

#include <cmath>

using namespace carto::maths;

float pgm::fx = 5.9421434211923247e+02;
float pgm::fy = 5.9104053696870778e+02;
float pgm::cu = 3.3930780975300314e+02;
float pgm::cv = 2.4273913761751615e+02;

float pgm::R[9] = {9.9984628826577793e-01, 1.2635359098409581e-03, -1.7487233004436643e-02,
                   -1.4779096108364480e-03, 9.9992385683542895e-01, -1.2251380107679535e-02,
                   1.7470421412464927e-02, 1.2275341476520762e-02, 9.9977202419716948e-01};
Vector3f pgm::T = Vector3f(1.9985242312092553e-02, -7.4423738761617583e-04, -1.0916736334336222e-02);
/*
float pgm::cx = 1.0950266051;
float pgm::cy = .9124876196;
float pgm::ox = .04651979;
float pgm::oy = .0518825414;
//*/
/*
float pgm::cx = .9760954873;
float pgm::cy = .8915603106;
float pgm::ox = .0382362501;
float pgm::oy = .0230908135;
//*/

Vector3f pgm::toRealCoordinates(const Vector2u &pixel, const float depth)
{
	// z = depth (found with depth camera)
    // x, y, z into the depth real's plan
    float z = depth;
    float x = ((pixel.x - pgm::cu) * z) / pgm::fx;
    float y = ((pixel.y - pgm::cv) * z) / pgm::fy;
    
    return Vector3f(x, y, z);
}

Vector3f pgm::toRGBCameraCoordinates(const Vector2u &pixel, const float depth)
{    
    Vector3f realCoord = toRealCoordinates(pixel, depth);

	// Return the rotated then translated matrix
    return matrix::translate3f(matrix::rotate3f(realCoord, R), T);
}

Vector2u pgm::toDepthImageCoordinates(const Vector3f &position)
{
	Vector3f coord = matrix::reverse_rotate3f(matrix::reverse_translate3f(position, T), R);

    unsigned int u = (unsigned int)(roundf((coord.x * pgm::fx) / coord.z + pgm::cu));
    unsigned int v = (unsigned int)(roundf((coord.y * pgm::fy) / coord.z + pgm::cv));

    return Vector2u(u, v);
}


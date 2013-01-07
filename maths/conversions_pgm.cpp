#include "conversions.h"

using namespace carto::maths;

float pgm::fx = 5.9421434211923247e+02;
float pgm::fy = 5.9104053696870778e+02;
float pgm::cu = 3.3930780975300314e+02;
float pgm::cv = 2.4273913761751615e+02;

Vector3f pgm::toRGBCameraCoordinates(const Vector2u &pixel, const float depth)
{
    // z = depth (found with depth camera)
    float z = depth;
    float x = ((pixel.x - pgm::cu) * z) / pgm::fx;
    float y = ((pixel.y - pgm::cv) * z) / pgm::fy;

    return Vector3f(x, y, z);
}

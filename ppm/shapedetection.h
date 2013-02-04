#ifndef SHAPEDETECTION_H
#define SHAPEDETECTION_H

#include "../maths/rectangle.h"
#include "image.h"

carto::maths::Rectangle shapeDetection(carto::ppm::Image& binarizedImage);

#endif // SHAPEDETECTION_H

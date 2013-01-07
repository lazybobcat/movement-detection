#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "vector.h"

namespace carto
{
    namespace maths
    {
        // Fonctions de convertion pour l'image RGB
        namespace ppm
        {
            Vector3f toRGBCameraCoordinates(const Vector2u& pixel);
        }

        // Fonctions de convertion pour l'image de profondeur
        namespace pgm
        {
            Vector3f toRGBCameraCoordinates(const Vector2u& pixel);
        }
    }
}

#endif // CONVERSIONS_H

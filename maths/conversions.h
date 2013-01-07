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
            extern float fx;    // Distance focale de la caméra à l'image
            extern float fy;    // Distance focale de la caméra à l'image
            extern float cu;    // Centre optique de la caméra = projection du centre de la caméra dans l'image
            extern float cv;    // Centre optique de la caméra

            /**
             * @brief Converts the coordinates of a local pixel in world coordinates. The depth we take is 1.
             * @param pixel The pixel position to convert
             * @param depth The pixel depth in meters
             * @return A vector with world coordinates (the depth [z] coordinates is 1)
             */
            Vector3f toRGBCameraCoordinates(const Vector2u& pixel, const float depth);

            /**
             * @brief Converts a world coordinate into a local (image) coordinate.
             * @param position The world coordinates
             * @return The coordinates in pixels (relative to the image)
             */
            Vector2u toRGBImageCoordinates(const Vector3f& position);
        }

        // Fonctions de convertion pour l'image de profondeur
        namespace pgm
        {
            extern float fx;    // Distance focale de la caméra à l'image
            extern float fy;    // Distance focale de la caméra à l'image
            extern float cu;    // Centre optique de la caméra = projection du centre de la caméra dans l'image
            extern float cv;    // Centre optique de la caméra

            /**
             * @brief Converts the coordinates of a local pixel in world coordinates. The depth we take is 1.
             * @param pixel The pixel position to convert
             * @param depth The pixel depth in meters
             * @return A vector with world coordinates (the depth [z] coordinates is 1)
             */
            Vector3f toRGBCameraCoordinates(const Vector2u& pixel, const float depth);

            /**
             * @brief Converts a world coordinate into a local (image) coordinate.
             * @param position The world coordinates
             * @return The coordinates in pixels (relative to the image)
             */
            Vector2u toDepthImageCoordinates(const Vector3f& position);
        }
    }
}

#endif // CONVERSIONS_H

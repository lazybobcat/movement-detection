#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <vector>

#include "vector.h"

namespace carto
{
    namespace maths
    {
        // Conversion functions for RGB camera
        namespace ppm
        {
            extern float fx;    ///< Focal Distance from camera to image
            extern float fy;    ///< Focal Distance from camera to image
            extern float cu;    ///< Camera Optical Center = projection of the camera center on the image
            extern float cv;    ///< Camera Optical Center

            /**
             * @brief Converts the coordinates of a local pixel in world coordinates.
             * @param pixel The pixel position to convert
             * @param depth The pixel depth in meters (found with depth camera)
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

        // Conversion functions for depth camera
        namespace pgm
        {
            extern float fx;            ///< Focal Distance from camera to image
            extern float fy;            ///< Focal Distance from camera to image
            extern float cu;            ///< Camera Optical Center = projection of the camera center on the image
            extern float cv;            ///< Camera Optical Center
            extern std::vector<float> R;///< Rotation parameters (to RGB camera)
            extern Vector3f T;          ///< Translation parameters (to RGB camera)

            /**
             * @brief Converts the coordinates of a local pixel in world coordinates.
             * @param pixel The pixel position to convert
             * @param depth The pixel depth in meters (found with depth camera)
             * @return A vector with world coordinates (the depth [z] coordinates is 1)
             */
            Vector3f toRGBCameraCoordinates(const Vector2u &pixel, const float depth);

            /**
             * @brief Converts a world coordinate into a local (image) coordinate.
             * @param position The world coordinates
             * @return The coordinates in pixels (relative to the image)
             */
            Vector2u toDepthImageCoordinates(const Vector3f &position);
        }
    }
}

#endif // CONVERSIONS_H

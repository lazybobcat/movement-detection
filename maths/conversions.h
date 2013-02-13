#ifndef CONVERSIONS_H
#define CONVERSIONS_H

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
            extern float fx;    ///< Focal Distance from camera to image
            extern float fy;    ///< Focal Distance from camera to image
            extern float cu;    ///< Camera Optical Center = projection of the camera center on the image
            extern float cv;    ///< Camera Optical Center
            extern float R[9];  ///< Rotation parameters (to RGB camera)
            extern Vector3f T;  ///< Translation parameters (to RGB camera)
            extern float cx;    ///< Correction for x coordinate
            extern float cy;    ///< Correction for y coordinate
            extern float ox;    ///< Correction offset for x coordinate
            extern float oy;    ///< Correction offset for y coordinate

			/**
			 * @brief 
			 * @param pixel The pixel's position to convert
			 * @param depth The pixel's depth in meters (found with depth camera)
			 * @return A vector with real coordinates
			 */
			Vector3f toRealCoordinates(const Vector2u &pixel, const float depth);

            /**
             * @brief Converts the coordinates of a local pixel in world coordinates.
             * @param pixel The pixel's position to convert
             * @param depth The pixel's depth in meters (found with depth camera)
             * @return A vector with RGB Camera coordinates
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

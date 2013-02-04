#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "vector.h"

namespace carto
{
    namespace maths
    {

        struct Rectangle
        {
            explicit Rectangle();
            Rectangle(unsigned int left, unsigned int top, unsigned int width, unsigned int height);
            Rectangle(const Vector2u& position, const Vector2u& size);

            unsigned int    left;
            unsigned int    top;
            unsigned int    width;
            unsigned int    height;
        };

    }
}

#endif // RECTANGLE_H

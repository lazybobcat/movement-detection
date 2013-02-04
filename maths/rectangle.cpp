#include "rectangle.h"

using namespace carto::maths;

Rectangle::Rectangle()
    : left(0),
      top(0),
      width(0),
      height(0)
{
}

Rectangle::Rectangle(unsigned int left, unsigned int top, unsigned int width, unsigned int height)
    : left(left),
      top(top),
      width(width),
      height(height)
{

}

Rectangle::Rectangle(const Vector2u& position, const Vector2u& size)
    : left(position.x),
      top(position.y),
      width(size.x),
      height(size.y)
{

}

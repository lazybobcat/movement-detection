#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <exception>
#include <vector>
#include "pixel.h"

namespace carto
{
namespace ppm
{

class Image
{
public:

    Image();
    Image(const std::string& filepath); // Open the file directly

    ~Image();

    void            create(unsigned short width, unsigned short height, unsigned char depth = 255);
    void            loadFromFile(const std::string& filepath) throw(std::exception);
    void            saveToFile(const std::string& filepath) throw(std::exception);
    const Pixel     at(unsigned short x, unsigned short y) const;

    void            setPixel(unsigned short x, unsigned short y, const Pixel& pixel);

    unsigned short  width() const;
    unsigned short  height() const;
    unsigned char   depth() const;

private:
    unsigned short      mWidth;         ///< The image width in pixels
    unsigned short      mHeight;        ///< The image height in pixels
    unsigned char       mColorDepth;    ///< The color depth should be 256 (from 0 to 255), so an unsigned char is perfect
    std::vector<Pixel>  mImage;         ///< The image without the first line (image informations) => table of pixels
};

} // namespace ppm
} // namespace carto

#endif // IMAGE_H

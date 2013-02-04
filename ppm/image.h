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

    Image& operator=(const Image&);

    ~Image();

    void            create();
    void            create(unsigned int width, unsigned int heigh);
    void            loadFromFile(const std::string& filepath) throw(std::exception);
    void            saveToFile(const std::string& filepath) throw(std::exception);
    const Pixel&    at(unsigned short x, unsigned short y) const;
    void            close();

    void            setPixel(unsigned short x, unsigned short y, const Pixel& pixel);

    unsigned short  width() const;
    unsigned short  height() const;
    unsigned short  depth() const;

private:
    void            loadHeaderFromFile(std::ifstream &file);

    unsigned short      m_width;         ///< The image width in pixels
    unsigned short      m_height;        ///< The image height in pixels
    unsigned short      m_colorDepth;    ///< The color depth (should be 255, but can be higher with better webcam)
    std::vector<Pixel>  m_image;         ///< The image without the first line (image informations) => table of pixels
};

} // namespace ppm
} // namespace carto

#endif // IMAGE_H

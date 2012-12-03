#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <exception>
#include <vector>

namespace ppm
{

    class Image
    {
    public:

        Image();
        Image(const std::string& filepath); // Open the file directly

        ~Image();

        void loadFromFile(const std::string& filepath) throw(std::exception);
        void saveToFile(const std::string& filepath) throw(std::exception);

    private:
        unsigned short      mWidth;         ///< The image width in pixels
        unsigned short      mHeight;        ///< The image height in pixels
        unsigned char       mColorDepth;    ///< The color depth should be 256 (from 0 to 255), so an unsigned char is perfect
    };

}

#endif // IMAGE_H

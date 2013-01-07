#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <exception>
#include <vector>

/*
  0.300215 : return value of getDepth on black pixel
  Correct value above .4 ?
  */

namespace carto
{
    namespace pgm
    {
        class Image
        {
        public:
            typedef enum { ASCII, BINARY } IMG_TYPE;

            /**
             * @brief Constructor
             * Default pgm image constructor
             */
            Image();

            /**
             * @brief Constructor
             * pgm image constructor from a file path
             * @param filepath : path of a pgm image file (*.pgm)
             */
            Image(const std::string &filepath);

            /**
             * @brief Constructor
             * Copy constructor
             * @param ori : constant reference of the original image to be copied
             */
            Image(const Image &ori);

            /**
             * @brief Destructor
             * pgm::Image class destructor
             */
            ~Image();

            /**
             * @brief Getter for an image's pixel depth
             * x is the x coord into the image
             * y is the y coord into the image
             */
            float getDepth(unsigned x, unsigned y) const;

            /**
             * @brief Load an image from a file
             * @param filepath : path of a pgm image file (*.pgm)
             * @throw [...]
             */
            void loadFromFile(const std::string &filepath) throw(std::exception);

            /**
             * @brief Save an image to a file
             * @param filepath : path of a pgm image file (*.pgm)
             * @throw [...]
             */
            void saveToFile(const std::string &filepath) throw(std::exception);

            /**
             * @brief Affectation operator
             * @param ori : constant reference of the original image to be copied
             * @return Reference to the Image, for multiple affectation (a = b = c)
             */
            Image &operator=(const Image &ori);

        private:
            /**
             * @brief Load the image header (P2 or P5)
             * @param file : an ifstream opened on a pgm file
             * @return Reference to the Image, for multiple affectation (a = b = c)
             */
            void loadHeaderFromFile(std::ifstream &file);

            IMG_TYPE                    m_imgType;      ///< The image type (from magic number) (ASCII or BINARY for respectively "P2" and "P5")
            unsigned short              m_width;        ///< The image width in pixels
            unsigned short              m_height;       ///< The image height in pixels
            unsigned short              m_start;        ///< The image start height
            unsigned int                m_colorDepth;   ///< The color depth should be 65536 (from 0 to 65535)
            std::vector<unsigned short> m_pixels;       ///< The image's pixels
        };
    }
}

#endif // IMAGE_H

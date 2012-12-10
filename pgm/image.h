#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <exception>

namespace carto
{
    namespace pgm
    {
        class Image
        {
        public:
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

            unsigned short      m_width;        ///< The image width in pixels
            unsigned short      m_height;       ///< The image height in pixels
            unsigned int        m_colorDepth;   ///< The color depth should be 65536 (from 0 to 65535)
        };
    }
}

#endif // IMAGE_H

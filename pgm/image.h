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
            typedef enum { UNKNOWN, ASCII, BINARY } IMG_TYPE;

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
             * @brief Convert a pixel distance to a meters distance
             * @param d the distance in pixels
             * @return the converted distance in meters
             */
            static inline float toMeters(unsigned short d)
            {
            	if(d < 2047.f)
       				return 1.f / (d * -0.0030711016 + 3.3309495161);
       				
       			return 0.f;
            }

            /**
             * @brief Getter for an image's pixel depth in meters
             * x is the x coord into the image
             * y is the y coord into the image
             * @return the pixel's depth in meters
             */
            float depth(unsigned x, unsigned y) const;

			/**
			 * @brief Getter for the image maximum depth in meters
			 * @return the maximum depth in meters
			 */
			float maxDepth() const;
			 
            /**
             * @brief Getter for the image's width
             */
            unsigned int width() const;

            /**
             * @brief Getter for the image's height. The 40% top are black
             */
            unsigned int height() const;

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

            /**
             * @brief Close the opened image and
             */
            void close();

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

#ifndef PIXEL_H
#define PIXEL_H


namespace carto
{
namespace ppm
{

/**
 * @brief The RGB Pixel structure. Contains a component for each color of the pixel and useful operators
 */
struct Pixel
{
    /**
     * @brief Pixel constructor, if you do not give color values, the pixel will be set to black(0,0,0)
     * @param red The red value [0,255]
     * @param green The green value [0,255]
     * @param blue The blue value [0,255]
     */
    Pixel(char red = 0, char green = 0, char blue = 0);

    /**
     * @brief Copy constructor, simply copy the rgb values
     * @param copy The pixel to copy
     */
    Pixel(const Pixel& copy);

    /**
     * @brief Copy operator, simply copy the rgb values
     * @param copy The pixel to copy
     */
    Pixel& operator=(const Pixel& copy);

    /**
     * @brief Comparison operator
     * @param other The pixel to be compared to
     * @return True if both Pixels are equals (if r, g and b values are equals wth the other pixel)
     */
    bool operator==(const Pixel& other);

    char    r; ///< The red value
    char    g; ///< The green value
    char    b; ///< The blue value

    static const Pixel Back;    ///< Pixel of black color : rgb(0,0,0)
    static const Pixel Red;     ///< Pixel of red color : rgb(255,0,0)
    static const Pixel Green;   ///< Pixel of green color : rgb(0,255,0)
    static const Pixel Blue;    ///< Pixel of blue color : rgb(0,0,255)
    static const Pixel White;   ///< Pixel of white color : rgb(255,255,255)
};

} // namespace ppm
} // namespace carto

#endif // PIXEL_H

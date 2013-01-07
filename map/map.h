#ifndef MAP_H
#define MAP_H

#include <vector>

#include "../pgm/image.h"

namespace carto
{
    /**
     *  @file   map.h
     *  @author
     *  @date   07/01/2013
     *  @brief  This class allow us to create the final map which will be used by the gui.
     */


    class Map
    {
        std::vector<float> m_map; ///< This vector contain the pixel's value (in meters).

    public:

        /**
         * @brief This method allow to convert pgm image in float vector.
         * @param pgmImage : is image to be converted
         */

        void convertPgmImageToMetersVector(pgm::Image *pgmImage);

        void analyzeMetersVector();
    };

}

#endif // MAP_H

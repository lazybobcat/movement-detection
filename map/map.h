#ifndef MAP_H
#define MAP_H

#include <vector>

#include "../maths/vector.h"
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
        std::vector<bool> m_binaryMap; ///< Vector filled by calling convertPgmImageToMetersVector

		unsigned short w;	///< The width in centimeters of the map
		unsigned short h;	///< The height in centimeters of the map
		
		/**
   		 * @brief Constructor without image but resize the vector
   		 * @param w [optional] the width in centimeters (integer)
    	 * @param h [optional] the height in centimeters (integer)
    	 */
    	Map(unsigned short w = 1000, unsigned short h = 500);
    public:
    	/**
    	 * @brief Main constructor of the class. Call makeMap method
    	 * @details the height given in parameters could be changed if too small !
    	 * @param pgmImage an image in pgm format
    	 * @param w [optional] the width in centimeters (integer)
    	 * @param h [optional] the height in centimeters (integer)
    	 */
    	Map(const pgm::Image &pgmImage, unsigned short w = 1000, unsigned short h = 500);
    	
    	/**
    	 * @brief Copy constructor
    	 * @param other the original Map
    	 */
    	Map(const Map &other);
    
		/**
		 * @brief Must be called before others operations. Called by main constructor.
		 * @param pgmImage an image in pgm format
		 */
        void makeMap(const pgm::Image &pgmImage);

        /**
          * @brief This method save the new map for using by IHM.
          *        Final map format : V for empty and R for not empty.
          */
        void saveMap(const std::string &fileName) const;
        
        /**
         * @brief Returns a translated map. Do not modify the map itself
         * @param T : vector of translation
         * @return The translated map
         */
        Map translated(const maths::Vector2d &T) const;
        
        /**
         * @brief Returns a rotated map. Do not modify the map itself
         * @param R : matrix of rotation 2*2
         * @return The rotated map
         */
        Map rotated(const float *R) const;
        
        /**
         * @brief Returns a translated then rotated map. Do not modify the map itself
         * @param T : vector of translation
         * @param R : matrix of rotation 2*2
         * @return The translated then rotated map
         */
        Map tr_map(const maths::Vector2d &T, const float *R) const;
        
        /**
         * @brief Returns a rotated then translated map. Do not modify the map itself
         * @param R : matrix of rotation 2*2
         * @param T : vector of translation
         * @return The rotated then translated map
         */
        Map rt_map(const float *R, const maths::Vector2d &T) const;
         
         /**
          * @brief Operator +
          * @param other the other map in the addition
          * @return the sum of the two maps
          */
         Map operator+(const Map &other) const;
    };

}

#endif // MAP_H

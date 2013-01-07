#include "map.h"

using namespace carto;

void Map::convertPgmImageToMetersVector(pgm::Image *pgmImage)
{
    unsigned int height = pgmImage->height();
    unsigned int width = pgmImage->width();

    for(unsigned int i = .4*height; i < height; ++i) // On multiplie par 0.4 car les 40% du haut de l'image sont noirs (cf classe Image)
    {
        for(unsigned int j = 0 ; j <  width ; ++j)
        {
            m_map.push_back(pgmImage->depth(i, j));
        }
    }
}

void Map::analyzeMetersVector()
{
    // Créer une classe pour les images contenant les "V" et "R" ?
    // A partir de quelle distance on dit qu'un pixel est "occupé" ?
    // Si un pixel est dit "occupé" on vérouille toute la colone ?
}

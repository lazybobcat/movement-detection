#include "shapedetection.h"
#include <map>
#include <vector>

#include <iostream>

using namespace carto::maths;

int numerotation(carto::ppm::Image& binarizedImage, std::vector<int>& numerotedImage, std::map<int , int>& numbersTable)
{
    int actualNumber = 0;
    // Travelling the picture on Y-axis (columns)
    for(unsigned int j = 1; j < binarizedImage.height(); ++j)
    {
        // Travelling the picture on X-axis (rows)
        for(int i = 1; i < binarizedImage.width()-1; ++i)
        {
            // If the pixel is white, it will be added to the shapes map. But we need to look at
            // neighbors pixels to number it correctly. As we travel in the picture from top left to bottom right,
            // we need to look at diagonal top left pixel, top pixel, left pixel and diagonal top right pixel.


            /// @todo: There are two cases. If the pixel is on the image border (i or j = 0) and the general case


            if(binarizedImage.at(i, j) == carto::ppm::Pixel::White)
            {
                int pixelNumber = 0;

                // Looking at TOP-LEFT pixel
                // If the TOP-LEFT pixel is white, we search it in the shapes map (it should have been numbered)
                if(binarizedImage.at(i-1, j-1) == carto::ppm::Pixel::White)
                {
                    // Get the TOP pixel index in the vector
                    int index = (j-1)*binarizedImage.width() + (i-1);

                    pixelNumber = numerotedImage[index];
                }


                // Looking at TOP pixel
                // If the TOP pixel is white, we search it in the shapes map (it should have been numbered)
                if(binarizedImage.at(i, j-1) == carto::ppm::Pixel::White)
                {
                    // Get the TOP pixel index in the vector
                    int index = (j-1)*binarizedImage.width() + i;

                    // If the pixel has already been set and is different than the looked pixel
                    if(pixelNumber != 0 && pixelNumber != numerotedImage[index])
                    {
                        numbersTable[numerotedImage[index]] = pixelNumber;
                    }
                    else
                        pixelNumber = numerotedImage[index];
                }

                // Looking at TOP-RIGHT pixel
                // If the TOP-RIGHT pixel is white, we search it in the shapes map (it should have been numbered)
                if(binarizedImage.at(i+1, j-1) == carto::ppm::Pixel::White)
                {
                    // Get the TOP pixel index in the vector
                    int index = (j-1)*binarizedImage.width() + (i+1);

                    // If the pixel has already been set and is different than the looked pixel
                    if(pixelNumber != 0 && pixelNumber != numerotedImage[index])
                    {
                        numbersTable[numerotedImage[index]] = pixelNumber;
                    }
                    else
                        pixelNumber = numerotedImage[index];
                }

                // Looking at LEFT pixel
                // If the LEFT pixel is white, we search it in the shapes map (it should have been numbered)
                if(binarizedImage.at(i-1, j) == carto::ppm::Pixel::White)
                {
                    // Get the TOP pixel index in the vector
                    int index = (j)*binarizedImage.width() + (i-1);

                    // If the pixel has already been set and is different than the looked pixel
                    if(pixelNumber != 0 && pixelNumber != numerotedImage[index])
                    {
                        numbersTable[numerotedImage[index]] = pixelNumber;
                    }
                    else
                        pixelNumber = numerotedImage[index];
                }


                // If none of the neighbors pixels has been set
                if(pixelNumber == 0)
                {
                    int index = j*binarizedImage.width() + i;
                    numerotedImage[index] = ++actualNumber;
                }
                else
                {
                    int index = j*binarizedImage.width() + i;
                    numerotedImage[index] = pixelNumber;
                }


            }
        }
    }

    return actualNumber;
}



Rectangle shapeDetection(carto::ppm::Image& binarizedImage)
{
    // Numeroter chaque pixel blanc et regarder ses voisins pour les traiter aussi
    std::vector<int>        numerotedImage(binarizedImage.width() * binarizedImage.height(), 0); // This will contain the numeroted pixels
    std::map<int , int>     numbersTable;   // Ths will contains the corresponding pixels (pixels numeroted differently but equivalent)

    std::cout << "Number of shapes : " << numerotation(binarizedImage, numerotedImage, numbersTable) << std::endl;

    // Renuméroter les pixels concomitants (ouah cte mot !)
    // Prendre la plus grande forme et retourner son rectangle englobant

    return Rectangle();
}

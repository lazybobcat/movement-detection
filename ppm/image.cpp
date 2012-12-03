#include "image.h"
#include <iostream>
#include <fstream>

using namespace carto::ppm;


Image::Image()
    : mWidth(0),
      mHeight(0),
      mColorDepth(0),
      mImage()
{
}


Image::Image(const std::string &filepath)
    : mWidth(0),
      mHeight(0),
      mColorDepth(0),
      mImage()
{
    // Load the image from file
    loadFromFile(filepath);
}

Image::~Image()
{

}


void Image::loadFromFile(const std::string &filepath) throw(std::exception)
{
    // Open the imagein binary mode
    std::ifstream file(filepath.c_str(), std::ios_base::binary);

    // Check if the file has been opened
    if(!file.is_open())
        throw std::ios_base::failure("The file cannot be opened");

    // We want to read the type of the file/magic number (for a binary ppm, it should be: P5)
    char fileType[3] = {0,0,0}; // Init it to 0 to have a null end caracter to terminate the string
    file.read(fileType, 2);

    if(std::string(fileType) != "P6")
        throw std::ios_base::failure("Wrong file type !");

    /// @toto Le reste de la fonction : lire la taille du fichier, allouer le tableau d'une taille suffisante, lire le fichier pixel par pixel et remplir le tableau.
}

















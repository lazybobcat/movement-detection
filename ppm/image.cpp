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

    // We want to read the type of the file/magic number (for a binary ppm, it should be: P6)
    char fileType[3] = {0,0,0}; // Init it to 0 to have a null end caracter to terminate the string
    file.read(fileType, 2);     // Read 2 caracters

    // If the file isn't a P6 type, then we cannot do anything
    if(std::string(fileType) != "P6")
        throw std::ios_base::failure("Wrong file type !");

    // Extract the header from file
    file >> mWidth >> mHeight >> mColorDepth;

    std::cout << "Image " << filepath << ": " << fileType << ", " << mWidth << "x" << mHeight << "x" << mColorDepth << std::endl;

    // Create the image in memory
    create();

    // Extract pixels
    unsigned char red, green, blue;
    unsigned int i = 0;
    while(!file.eof())
    {
        file.read(reinterpret_cast<char*>(&red), sizeof(unsigned char));
        file.read(reinterpret_cast<char*>(&green), sizeof(unsigned char));
        file.read(reinterpret_cast<char*>(&blue), sizeof(unsigned char));

        mImage[i] = Pixel(red, green, blue);
        ++i;

        //std::cout << "Pixel : " << (int)red << " " << (int)green << " " << (int)blue << std::endl;
    }
}


void Image::create()
{
    mImage.reserve(mWidth*mHeight);
}

void Image::setPixel(unsigned short x, unsigned short y, const Pixel &pixel)
{
    // Get the linear position from x and y
    unsigned int position = y*mWidth + (x + 1);
    mImage[position] = pixel;
}


const Pixel& Image::at(unsigned short x, unsigned short y) const
{
    // Get the linear position from x and y
    unsigned int position = y*mWidth + (x + 1);
    return mImage[position];
}
















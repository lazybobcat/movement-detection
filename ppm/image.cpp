#include "image.h"
#include <iostream>
#include <fstream>

using namespace carto::ppm;


Image::Image()
    : m_width(0),
      m_height(0),
      m_colorDepth(0),
      m_image()
{
}


Image::Image(const std::string &filepath)
    : m_width(0),
      m_height(0),
      m_colorDepth(0),
      m_image()
{
    // Load the image from file
    loadFromFile(filepath);
}

Image::~Image()
{

}

Image& Image::operator=(const Image& copy)
{
    m_width = copy.m_width;
    m_height = copy.m_height;
    m_colorDepth = copy.m_colorDepth;
    m_image.resize(copy.m_image.size());
    m_image = copy.m_image;
    return *this;
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
    file >> m_width >> m_height >> m_colorDepth;

    std::cout << "Image " << filepath << ": " << fileType << ", " << m_width << "x" << m_height << "x" << m_colorDepth << std::endl;

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

        m_image.push_back(Pixel(red, green, blue));
        ++i;

        //std::cout << "Pixel : " << (int)red << " " << (int)green << " " << (int)blue << std::endl;
    }
}

void Image::saveToFile(const std::string &filepath) throw(std::exception)
{
    std::ofstream file(filepath.c_str(), std::ios_base::binary);

    // Check if the file has been opened
    if(!file.is_open())
        throw std::ios_base::failure("The file cannot be opened");

    file << "P6 " << m_width << " " << m_height << " " << m_colorDepth;

    for(unsigned int i = 0; i < m_image.size(); ++i)
    {
        //std::cout << "Writing " << m_image[i].r << ", " << m_image[i].g << ", " << m_image[i].b << ", " << std::endl;
        file.write(reinterpret_cast<char*>(&m_image[i].r), sizeof(unsigned char));
        file.write(reinterpret_cast<char*>(&m_image[i].g), sizeof(unsigned char));
        file.write(reinterpret_cast<char*>(&m_image[i].b), sizeof(unsigned char));
    }

    file.close();
    std::cout << "Image saved to " << filepath << std::endl;
}


void Image::create()
{
    m_image.reserve(m_width*m_height);
}

void Image::setPixel(unsigned short x, unsigned short y, const Pixel &pixel)
{
    // Get the linear position from x and y
    unsigned int position = y*m_width + (x + 1);
    m_image[position] = pixel;
}


const Pixel& Image::at(unsigned short x, unsigned short y) const
{
    // Get the linear position from x and y
    unsigned int position = y*m_width + (x + 1);
    return m_image[position];
}


unsigned short  Image::width() const
{
    return m_width;
}
unsigned short  Image::height() const
{
    return m_height;
}
unsigned short Image:: depth() const
{
    return m_colorDepth;
}















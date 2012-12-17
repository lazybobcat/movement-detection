#include "image.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace carto;

void pgm::Image::loadFromFile(const std::string& filepath) throw(std::exception)
{
    std::ifstream file(filepath.c_str(), std::ifstream::in | std::ios_base::binary);
    unsigned short *data;
    unsigned fullsize, start;

    if(!file.is_open())
        throw std::ios_base::failure("Error opening file");

    try
    {
        loadHeaderFromFile(file);
    }
    catch(std::runtime_error e)
    {
        file.close();
        std::cerr << e.what() << std::endl;

        throw;
    }

    fullsize = m_width * m_height;
    start = m_width * m_start;

    data = new unsigned short[fullsize];
    m_pixels.reserve(fullsize);

    switch(m_imgType)
    {
    case ASCII:
        // To do
        break;
    case BINARY:
        file.read((char *)data, fullsize * sizeof(unsigned short));

        /*
          The first loop fill the 40% of the image's top with black
          The second loop use data read
          This save the 60% of the image's bottom, keeping the original image size
          for compatibility with the other format (ppm)
          */
        for(unsigned i = 0; i < start; ++i)
            m_pixels.push_back(0);
        for(unsigned i = start; i < fullsize; ++i)
            m_pixels.push_back(data[i]);

        break;
    }

    delete [] data;

    file.close();
}

void pgm::Image::saveToFile(const std::string& filepath) throw(std::exception)
{
    std::ofstream file(filepath.c_str(), std::ifstream::out | std::ios_base::binary);

    if(!file.is_open())
        throw std::ios_base::failure("Error opening file");

    switch(m_imgType)
    {
    case ASCII:/*
        file << "P2\n# Saved by Robot Project\n" << m_width << " " << m_height << std::endl << m_colorDepth << std::endl;

        for(unsigned i = 0; i < m_pixels.size(); ++i)
        {
            if(!(i % m_width) && i)  file << std::endl;
            file << m_pixels[i] << "  ";    // Two spaces for format
        }
        */break;
    case BINARY:
        file << "P5\n# Saved by Robot Project\n" << m_width << " " << m_height << std::endl << m_colorDepth << std::endl;

        for(unsigned i = 0; i < m_pixels.size(); ++i)
            // It is not possible to use << operator for write binary datas
            file.write(reinterpret_cast<const char *>(&m_pixels[i]), sizeof(unsigned short));
        break;
    }
    file.close();
}

void pgm::Image::loadHeaderFromFile(std::ifstream &file)
{
    char            c;              // the char read with file.get
    char            bin[1024];      // unused data read
    std::string     magic_num;      // magic number (P2 <=> ASCII and P5 <=> BINARY)

    /*
      data will contain :
        P2 for ASCII mode or P5 for binary mode
        the image width
        the image height
        the image maximum depth (from 0 to 65535)
      with a space between each data
     */
    std::string     data;
    unsigned        datacount = 0;  // current data read

    while(datacount < 4)
    {
        file.get(c);

        /*  SPACE  || HT, LF, VT, FF, CR
            these chars are data separators
         */
        if(c == 32 || (c >= 9 && c <= 13))
        {
            ++datacount;                    // go to next data
            data += " ";                    // adding space separator between datas
        }
        else if(c == '#')                   // # indicate that all line at its right is comment
            file.getline(bin, 1024);        // read the full line into unused variable
        else
            data += c;                      // append the caracter read to current data
    }

    std::stringstream ss(data);
    ss >> magic_num;

    if(magic_num == "P2")
        m_imgType = ASCII;
    else if(magic_num == "P5")
        m_imgType = BINARY;
    else
        throw std::runtime_error("Error : invalid file format");

    ss >> m_width >> m_height >> m_colorDepth;
    m_start = m_height * .4;
}

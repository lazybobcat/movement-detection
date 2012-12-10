#include "image.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <stdexcept>

using namespace carto;

pgm::Image::Image()
{
}

pgm::Image::Image(const std::string &filepath)
{
    loadFromFile(filepath);
}

pgm::Image::Image(const pgm::Image &ori)
{
}

pgm::Image::~Image()
{
}

void pgm::Image::loadFromFile(const std::string& filepath) throw(std::exception)
{
    std::ifstream file(filepath.c_str(), std::ifstream::in | std::ios_base::binary);
    char *data;
    unsigned fullsize;

    if(file.is_open())
    {
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
        data = new char[fullsize];
        m_pixels.reserve(fullsize);

        /*
          We only take 60 percents of the full image
          The high part is not useful */
        /*m_height *= .6;*/

        switch(m_imgType)
        {
        case ASCII:
            // file >>
            break;
        case BINARY:
            file.read(data, fullsize);
            for(unsigned i = 0; i < fullsize; ++i)
                m_pixels.push_back(data[i]);
            break;
        }

        delete [] data;

        file.close();
    }
    else
        throw std::ios_base::failure("Error opening file");
}

void pgm::Image::saveToFile(const std::string& filepath) throw(std::exception)
{
    std::ofstream file(filepath.c_str(), std::ifstream::out | std::ios_base::binary);
    
    file << "P5\n# Saved by Robot Project\n" << m_width << " " << m_height << "\n" << m_colorDepth << "\n";
    
    for(int i = 0; i < m_pixels.size(); ++i)
        file << m_pixels[i];
    
    file.close();
}

pgm::Image &pgm::Image::operator=(const pgm::Image &ori)
{
    return *this;
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

    std::cerr << m_imgType << " " << m_width << " " << m_height << " " << m_colorDepth << std::endl;
}

int main()
{
    pgm::Image a("/home/celforyon/projet/projet/pgm/test.pgm");
    
    a.saveToFile("/home/celforyon/projet/projet/pgm/save.pgm");

    return 0;
}



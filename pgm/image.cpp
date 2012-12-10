#include "image.h"

#include <iostream>
#include <fstream>
#include <sstream>

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
    std::ifstream file(filepath.c_str(), std::ifstream::in);

    if(file.is_open())
    {
        loadHeaderFromFile(file);
        file.close();
    }
    else
        throw std::ios_base::failure("Error opening file");
}

void pgm::Image::saveToFile(const std::string& filepath) throw(std::exception)
{
}

pgm::Image &pgm::Image::operator=(const pgm::Image &ori)
{
	return *this;
}

void pgm::Image::loadHeaderFromFile(std::ifstream &file)
{
    char            c;              // the char read with file.get
    char            bin[1024];      // unused data read

    /*
      data[0] will contain P2 for ASCII mode or P6 for binary mode
      data[1] will contain the image width
      data[2] will contain the image height
      data[3] will contain the image maximum depth (from 0 to 65535)
     */
    std::string     data[4];
    unsigned        datacount = 0;  // current data read

    while(datacount < 4)
    {
        file.get(c);

        /*  SPACE  || HT, LF, VT, FF, CR
            these chars are data separators
         */
        if(c == 32 || (c >= 9 && c <= 13))
            ++datacount;                    // go to next data
        else if(c == '#')                   // # indicate that all line at its right is comment
            file.getline(bin, 1024);        // read the full line into unused variable
        else
            data[datacount] += c;           // append the caracter read to current data
    }

    // data[0] currently not used
    std::stringstream ss(data[1]);
    ss >> m_width;

    std::stringstream ss(data[1]);
    ss >> m_height;

    std::cout << m_width << std::endl;
}

int main()
{
    pgm::Image a("/home/celforyon/projet/pgm/test.pgm");

	return 0;
}



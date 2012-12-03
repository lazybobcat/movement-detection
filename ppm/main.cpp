#include <iostream>
#include "pixel.h"

using namespace std;
using namespace ppm;

int main()
{
    Pixel p1(128,140,25);
    Pixel p2(p1);
    Pixel p3;

    if(p2 == p1) { cout << "P2 = P1" << endl; }
    p3 = p1;
    if(p3 == p1) { cout << "P3 = P1" << endl; }
    p3.r = 0;
    if(p3 == p1) { cout << "P3 = P1" << endl; }

    return 0;
}


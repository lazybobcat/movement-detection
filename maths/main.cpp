#include "conversions.h"
#include "../pgm/image.h"

#include <iostream>

using namespace std;

using namespace carto::maths::pgm;
using namespace carto::maths;
using namespace carto::pgm;

// Position à analyser :
#define X   384
#define Y   296

int main()
{
    Image img("/home/celforyon/record/d-1353926266.106240-2126802651.pgm");

    Vector3f real = toRGBCameraCoordinates(Vector2u(X, Y), img.depth(X, Y));

    Vector2u d = toDepthImageCoordinates(real);

    if(d.x == X && d.y == Y)
    {
        // Affichage des coordonnées de retour
        cout << "[x = " << d.x << "; y = " << d.y << "]" << endl;
        cout << "[x = " << real.x << "; y = " << real.y << "; z = " << real.z << "]" << endl;
    }
    else
        cerr << "Invalid coordinates !" << endl;

    return 0;
}

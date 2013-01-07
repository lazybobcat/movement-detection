#include "conversions.h"

using namespace carto::maths;

/*
Paramètres intrasèques à la caméra :
Cu : Centre optique de la caméra
Cv : Centre optique de la caméra = projection du centre de la caméra dans l'image
Fx : Distance focales
Fy : Distance focale


                                        (Fx  0  Cu)
On les modélise dans une matrice K =    (0  Fy  Cv)
                                        (0   0  1 )

        (x)
Pts =	(y)
        (z)

On peut faire K*Pts = pts_image  mais qui aura 3 composantes (Su, Sv, S) !

Su = x*Fx + 0 + Cu*z
Sv = 0 + y*Fy + Cv*z
S = z = 1

Et donc dans notre image : Modèle sténopé (Pinhole)
u = (x*Fx)/z + Cu
v = (y*Fy)/z + Cv

On a passé un point du monde réel au coordonnées image.


Pour passer des coordonnées images au coordonées monde réel :
On a z depuis la Kinect,
x = ((u - Cu)*z)/Fx
y = ((v - Cv)*z)/Fy




Pour passer à l'autre caméra il  a encore une translation (et une rotation) [R et t] à appliquer :
> profondeur vers RGB <

    (xt)
t = (yt)
    (zt)


R = (ax, ay, az) -> convertie en matrice [3x3] donnée

ptsP = (xd, yx, zd)
On veut ptsRGB qui correspond à ptsP
ptsRGB = R * ptsD + t


*/

float ppm::fx = 5.2921508098293293e+02;
float ppm::fy = 5.2556393630057437e+02;
float ppm::cu = 3.2894272028759258e+02;
float ppm::cv = 2.6748068171871557e+02;

Vector3f ppm::toRGBCameraCoordinates(const Vector2u& pixel, const float depth)
{
    // Passage des coordonnées image en coordonnées "monde réel"
    // x = ((u - Cu)*z)/Fx  où u = pixel.x
    // y = ((v - Cv)*z)/Fy  où v = pixel.y
    // z = depth (found with depth camera)
    float z = depth;
    float x = ((pixel.x - ppm::cu)*z)/ppm::fx;
    float y = ((pixel.y - ppm::cv)*z)/ppm::fy;

    return Vector3f(x, y, z);
}

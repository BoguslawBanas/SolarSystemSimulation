#ifndef PLANET_VIEW_H
#define PLANET_VIEW_H

#include <raylib.h>

class Planet_View{
    public:
    static void draw(const Model&, const Vector3&, const double, const double, const float);

    static void draw(const Model&, const Vector3&, const double, const double, const float, const float);

    static void markPlanet(const Vector3&, const double, const double, const double);
};

#endif
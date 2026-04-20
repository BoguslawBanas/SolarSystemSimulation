#ifndef PLANET_VIEW_H
#define PLANET_VIEW_H

#include <raylib.h>

class Planet_View{
    private:

    public:
    Planet_View();

    ~Planet_View();

    // static void draw(const Vector3&, const double, const Color&, const double, const double);

    static void draw(const Model&, const Vector3&, const double, const double);

    static void markPlanet(const Vector3&, const double, const double, const double);
};

#endif
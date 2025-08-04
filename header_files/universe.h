#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include "planet.h"

class Universe{
    public: //tmp later change to private
    std::vector<Planet>planets;

    public:
    Universe();

    ~Universe();

    void addPlanetToUniverse(const Planet&);

    void calculateGravitiesOfPlanets(const double);

    void drawUniverse(const double, const double);
};

#endif
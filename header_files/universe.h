#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include "planet.h"
#include <math.h>

class Universe{
    private: //tmp later change to private
    std::vector<Planet>planets;
    Planet *tmp_planet;

    public:
    Universe();

    ~Universe();

    std::vector<Planet>& getPlanets();

    Planet* getTmpPlanet() const;

    void addPlanetToUniverse(const Planet&);

    void calculateGravitiesOfPlanets(const double);

    void drawUniverse(const double, const double);

    void addTmpPlanetToUniverse(const Color);

    void deleteTmpPlanetFromUniverse();

    void setOptionsForTmpPlanet(const long double, const long double, const float, const long double, const long double, const Color);

    void acceptPlanetToUniverse();

    void deletePlanetsFromUniverse(const std::vector<char>&);
};

#endif
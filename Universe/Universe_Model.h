#ifndef UNIVERSE_MODEL_H
#define UNIVERSE_MODEL_H

#include <vector>
#include "../Planet/Planet_Model.h"

class Universe_Model{
    private:
    std::vector<Planet_Model*>planets;
    Planet_Model *tmp_planet;
    float calc_speed;

    public:
    Universe_Model();

    ~Universe_Model();

    const std::vector<Planet_Model*>& getPlanets() const;

    const Planet_Model* getTmpPlanet() const;

    void addPlanet(Planet_Model*);

    void addPlanet(const Planet_Model&);

    void removePlanet(const std::vector<int>&);

    void removeAllPlanets();

    void createTmpPlanet();

    void updateTmpPlanet(const double, const double, const Vector3&, const Vector3&, const Color&);

    void deleteTmpPlanet();

    void calcNewPositionsOfPlanets(const float);
};

#endif
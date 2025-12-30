#ifndef UNIVERSE_CONTROLLER_H
#define UNIVERSE_CONTROLLER_H

#include "Universe_Model.h"
#include "Universe_View.h"
#include "../Planet/Planet_Controller.h"

class Universe_Controller{
    private:
    Universe_Model *model;
    Universe_View *view;

    public:
    Universe_Controller(const double, const double);

    ~Universe_Controller();

    const Universe_Model* const getModel() const;

    void addPlanet(const Vector3, const Vector3, const double, const double, const Color, const char*);

    void addTmpPlanet();

    void addTmpPlanetToUniverse();

    void deleteTmpPlanet();

    void removePlanet();

    void removeAllPlanets();

    void updateNewPositionsOfPlanets(const float);

    void updateTmpPlanet(const double, const double, const Vector3&, const Vector3&, const Color&);

    void requestDrawing();
};

#endif
#ifndef PLANET_CONTROLLER_H
#define PLANET_CONTROLLER_H

#include "Planet_Model.h"
#include "Planet_View.h"

class Planet_Controller{
    private:
    Planet_Model *model;
    Planet_View *view;

    public:
    Planet_Controller();

    Planet_Controller(const Vector3, const Vector3, const double, const double, const Color, const char*);

    ~Planet_Controller();

    void calcNewPosition() const;

    void requestDrawing(const double, const double) const;

    bool isCursorOnThePlanet(const Camera3D&, const double, const double) const;
};

#endif
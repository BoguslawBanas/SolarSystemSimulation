#ifndef GRAVITATIONAL_GRID_2D_CONTROLLER_H
#define GRAVITATIONAL_GRID_2D_CONTROLLER_H

#include "Gravitational_Grid_2D_Model.h"
#include "Gravitational_Grid_2D_View.h"

class Gravitational_Grid_2D_Controller{
    private:
    Gravitational_Grid_2D_Model *model;
    Gravitational_Grid_2D_View *view;

    public:
    Gravitational_Grid_2D_Controller(const double, const unsigned, const double, const double);

    ~Gravitational_Grid_2D_Controller();

    void calcLogic(const std::vector<Planet_Model*>&);

    void requestDrawing();
};

#endif
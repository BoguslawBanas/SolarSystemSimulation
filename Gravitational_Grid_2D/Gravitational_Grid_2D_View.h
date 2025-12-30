#ifndef GRAVITATIONAL_GRID_2D_VIEW_H
#define GRAVITATIONAL_GRID_2D_VIEW_H

#include <math.h>

class Gravitational_Grid_2D_View{
    private:
    double distance_divider;

    public:
    Gravitational_Grid_2D_View(const double);

    ~Gravitational_Grid_2D_View();

    void draw(const float, const unsigned, const float, float** const);
};

#endif
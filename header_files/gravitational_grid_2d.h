#ifndef GRAVITATIONAL_GRID_2D
#define GRAVITATIONAL_GRID_2D

#include <vector>
#include <raylib.h>
#include <math.h>
#include "planet.h"
#include "solar_system_consts.h"

class Gravitational_Grid_2D{
    private:
    Vector2 start_pos;
    int amount_of_nodes;
    double default_height_of_grid;
    Vector3 *grid;
    
    public:
    Gravitational_Grid_2D(const Vector2&, const int, const double);

    ~Gravitational_Grid_2D();

    void calculateGrid(const std::vector<Planet>&);

    void drawGrid(const double);
};

#endif
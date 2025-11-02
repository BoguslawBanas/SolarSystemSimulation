#ifndef GRAVITATIONAL_GRID_2D
#define GRAVITATIONAL_GRID_2D

#include <vector>
#include <raylib.h>
#include <math.h>
#include "planet.h"
#include "solar_system_consts.h"

class Gravitational_Grid_2D{
    private:
    float start_pos;
    unsigned amount_of_nodes;
    float default_height_of_grid;
    float distance_divider;
    float grid_delta;
    float **grid;

    float calcGridDelta();
    
    public:
    Gravitational_Grid_2D();

    Gravitational_Grid_2D(const float, const int, const float, const float);

    ~Gravitational_Grid_2D();

    void setStartPos(const float);

    void setAmountOfNodes(const unsigned);

    void setDefaultHeightOfGrid(const float);

    void setDistanceDivider(const float);

    void calculateGrid(const std::vector<Planet>&);

    void drawGrid(const double);
};

#endif
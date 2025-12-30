#ifndef GRAVITATIONAL_GRID_2D_MODEL_H
#define GRAVITATIONAL_GRID_2D_MODEL_H

#include <vector>
#include <pthread.h>
#include "../Planet/Planet_Model.h"

struct Calc_Grid_Str{
    Vector3 pos;
    double mass;
    double start_pos;
    unsigned amount_of_nodes;
    double grid_delta;
    float **grid;

    Calc_Grid_Str();
};

void* calcLogicSingleThread(void*);

class Gravitational_Grid_2D_Model{
    private:
    double start_pos;
    unsigned amount_of_nodes;
    double default_height_of_the_grid;
    double grid_delta;
    float **grid;

    double calcGridDelta();

    public:
    Gravitational_Grid_2D_Model(const double, const unsigned, const double);

    ~Gravitational_Grid_2D_Model();

    double getStartPosition() const;

    double getDefaultHeightOfTheGrid() const;

    unsigned getAmountOfNodes() const;

    double getGridDelta() const;

    float** const getGrid() const;

    void calcLogic(const std::vector<Planet_Model*>&);
};

#endif
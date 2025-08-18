#ifndef SIMULATION_H
#define SIMULATION_H

#define RAYGUI_IMPLEMENTATION
#define DISTANCE_CONST 5e6l
#define DIVIDE_CONST 1e4l

#include <raylib.h>
#include <raymath.h>
#include "universe.h"
#include "gravitational_grid_2d.h"
#include <string>
#include <map>

enum Simulation_State{
    START_MENU,
    START_MENU_2,
    SIMULATION,
    ADD_PLANET_MENU,
    DELETE_PLANET_MENU,
    PAUSE,
    EXIT
};

class Simulation{
    private:
    Universe *universe;
    Gravitational_Grid_2D *grid2d;
    Camera3D camera;
    Simulation_State state;
    int window_width;
    int window_height;
    std::map<std::string, bool> buttons;

    public:
    Simulation(int, int);

    ~Simulation();

    Simulation_State getState() const;

    void calcLogic();

    void drawSimulation();
};

#endif
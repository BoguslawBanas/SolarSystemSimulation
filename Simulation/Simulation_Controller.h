#ifndef SIMULATION_CONTROLLER_H
#define SIMULATION_CONTROLLER_H

#include "Simulation_Model.h"
#include "Simulation_View.h"
#include "../Universe/Universe_Controller.h"
#include "../Main_Menu/Main_Menu_Controller.h"
#include "../Add_Planet_Menu/Add_Planet_Menu_Controller.h"
#include "../Gravitational_Grid_2D/Gravitational_Grid_2D_Controller.h"
#include "../Start_Menu/Start_Menu_Controller.h"

class Simulation_Controller{
    private:
    Camera3D camera;
    Music music;
    Simulation_Model *simulation_model;
    Simulation_View *simulation_view;
    Universe_Controller *universe_controller;
    Main_Menu_Controller *main_menu;
    Add_Planet_Menu_Controller *add_planet_menu;
    Gravitational_Grid_2D_Controller *grid;
    Start_Menu_Controller *start_menu;
    
    bool is_esc_clicked;

    void calcLogic();

    void drawNextFrame();

    public:
    Simulation_Controller(const char*);

    ~Simulation_Controller();

    void simulationLoop();

    Universe_Controller *getUniverseController();
};

#endif